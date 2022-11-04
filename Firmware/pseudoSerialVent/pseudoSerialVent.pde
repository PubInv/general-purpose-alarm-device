/** pseudoSerialVent //<>//
 *
 * /author F. Lee Erickson.
 * /date 28 October 2022.
 * /brief A Proccessing program to simulate a PolyVent on a serial interface to the GPAD.
 * 
 
 * /detail Modified from ServerComeAndGoes at: https://github.com/ForrestErickson/Processing-ServerComeAndGoes
 * 20221103 Version 0.0.2 Fix inverted keyboard mute text. Change background color to indicate command sent to serial port.
 * 20221104 Version 0.0.3 Report button pressed, Read and report status of MUTE.
 *
 */

String COMPANY = "Public Invention";
String MODELNAME = "pseudoSerialVent";
String VERSION = "0.0.3";


//final int COMPORT_INDEX = 3;    //Change the port number as necessary
final int COMPORT_INDEX = 4;    //Change the port number as necessary
//final int COMPORT_INDEX = 5;    //Change the port number as necessary
String outString = "Hello World";  // Output string to serial port
String inString;  // Input string from serial port


import processing.serial.*;

int lf = 10;    // Linefeed in ASCII
int cr = 13;    // CR in ASCII
String myString = null;
Serial myPort;  // The serial port
int BAUDRATE = 115200 ;

// DUT stat variables received

Boolean dutMuted = false; 

//Variables to measure DUT response time
int timeSerialSent = 0;
int timeSerialReceived = -1;  //Set for negative to start so the message will wait for the first command.
int timeCommandProccess = 0;

//Old code from socket version
String mySocket = "None";
String myOldSocket = "None";
Boolean Verbose = true; 

import processing.net.*;

Server myServer;
Client myClient;
Client thisClient;
//String MY_IP_WIFI = "10.123.45.3";
String MY_IP_WIFI = "Wi-Fi";

int MY_PORT = 23; // Start on Telnet even though we are RAW socket.
boolean myServerRunning;

PFont f;                          // Declare regular body text PFont variable
PFont fBig;                          // Declare heading PFont variable

String input;
int data[];
int dataIn;
float myred = 0; 
float mygreen= 0; 
float myblue = 0;
color myBackground = color(255, 0, 0);
//int myBackground = 0;

/* User Interface */
int yInstructionLocation = 100;
int yInstructionNextLine = 18;

String s_serverStatus = "Not initilized";
String s_clientStatus = "Not initilized";
String s_clientAddress = "Not initilized";
String s_messageServer = "Not initilized";
String s_messageClient = "Not initilized";

/* Support Functions */


/*This function is called when a client disconnects. */
void disconnectEvent(Client myClient) {
  /* Make background lighter for each connection event.*/
  myred = constrain( (red(myBackground) -64), 0, 255);  
  mygreen = constrain( (green(myBackground) -64), 0, 255);  
  myblue = constrain( (blue(myBackground) -64), 0, 255);  
  myBackground = color(myred, mygreen, myblue) ;
  s_clientStatus = "Client " + myClient.ip() + " has disconnected";
  appendTextToFile(myLogFileName, ("Client disconnect: " + myClient.ip()));
  s_messageClient = "";
  println("Client disconnect: " + myClient.ip());
}

// ServerEvent message is generated when a new client connects to an existing server.
void serverEvent(Server myServer, Client myClient) {
  s_clientAddress = myClient.ip();
  println("\nWe have a new socket client: " + s_clientAddress);
  appendTextToFile(myLogFileName, "Client connected: " + s_clientAddress );
  myred = constrain( (red(myBackground) +64), 0, 255);  
  mygreen = constrain( (green(myBackground) +64), 0, 255);  
  myblue = constrain( (blue(myBackground) +64), 0, 255);  
  myBackground = color(myred, mygreen, myblue) ;
  s_clientStatus = "Client connected: " + s_clientAddress;
}


void setup() 
{  
  // List all the available serial ports
  printArray(Serial.list());
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[COMPORT_INDEX], BAUDRATE);  //Arduino
  myPort.bufferUntil(lf); 
  myPort.clear();
  // Throw out the first reading, in case we started reading 
  // in the middle of a string from the sender.
  // myString = myPort.readStringUntil(lf);
  myString = null;


  frameRate(60);  
  background (myBackground);
  size(600, 600); 
  surface.setTitle(COMPANY + ", " + MODELNAME + ", Version: " + VERSION);
  String startTime = (str(year()) + str(month()) +str(day()) +"_" + str(hour()) + str(minute()) + str(second()) );
  myLogFileName = (startTime + "_" + myLogFileName);
  appendTextToFile(myLogFileName, ("Your log is born."));

  f = createFont("Arial", 12, true);     // Create Font 
  fBig = createFont("Arial", 18, true);     // Create Font for heading 
  textAlign(LEFT);                    // Credit will be in lower right corner.
  text("Set up started", 400, 10);

  /*Set up server. This coorisponds to sl_Socket which opens a socket, 
   and sl_Bind which is where we set port, 
   and sl_Listen where we start listening.
   */
  myServer = new Server(this, MY_PORT);
  //  myServer = new Server(this, MY_PORT, MY_IP_WIFI);
  text("Server started", 400, 10);  
  if (myServer.active() == true) {
    myBackground = color(0, 0, 0);
    s_serverStatus = "Start up server is active.";
    myServerRunning = true;
  } else {
    myServerRunning = false;
  }
  //Request the help string to syncronice with GPAD status.
  outString = "h";
  myPort.write(outString);
  myBackground = color(255, 0, 0); //Red indicated command sent.
} // setup()

void draw() {
  String s_ResponseTime = "NULL";
  yInstructionLocation = 100; //Reset location for next instruction line
  textAlign(LEFT); 

  // Process serial port read
  background (myBackground);
  text("Sent to GPAD: " + outString, 10, 430); 
  text("Received from GPAD: " + inString, 10, 450); 
  timeCommandProccess = timeSerialReceived - timeSerialSent;
  if (  timeCommandProccess <0 ) {
    s_ResponseTime = "Waiting";
    text("Time to process command from GPAD: " + s_ResponseTime, 10, 470); 
    text("Buzzer is: UNKNOWN", 10, 490);
  } else {
    s_ResponseTime = str(timeCommandProccess);
    text("Time to process command from GPAD: " + s_ResponseTime, 10, 470); 
    //Indicate the status of the DUT mute.
    if (dutMuted == true) {
      text("Buzzer is: MUTED", 10, 490);
    } else {
      text("Buzzer is: NOT MUTED", 10, 490);
    }
  }

  //If background red messag to user that command is on process.
  if (myBackground == color(255, 0, 0)) {
    textFont(fBig);
    text("STALE STATE, WAITING FOR RESPONSE FROM DUT", 10, 20);
    textFont(f);  //Back to regular
  }




  ////Process server IO
  //if (myServerRunning) {
  //  background (myBackground);
  //  mySocket = " IP: " + Server.ip() + ":" + str(MY_PORT);
  //  if (mySocket.equals(myOldSocket) == false) {
  //    appendTextToFile(myLogFileName, ("Server socket changed from: " + myOldSocket + " to: " + mySocket ));
  //    String myTime = (str(year()) + str(month()) +str(day()) +"_" + str(hour()) + str(minute()) + str(second()) );
  //    println(myTime + " Server socket changed from: " + myOldSocket + " to: " + mySocket );
  //    myOldSocket = mySocket;
  //  }
  //  text(s_serverStatus + mySocket, 400, 10);
  //  //    text(s_serverStatus + " IP: " + Server.ip() + ":" + str(MY_PORT) ,400, 10);
  //  text("Client Connection: "+s_clientStatus, 400, 20);
  //  text("Client: " + s_messageClient, 400, 40);
  //  text("Server:" + s_messageServer, 400, 50);    
  //  printUserInstructions();

  //  thisClient = myServer.available();
  //  // If the client is not null, and says something, display what it said
  //  if (thisClient !=null) {
  //    text("Client transmitting", 400, 30);
  //    myClient = thisClient;  // Save off the client object for the key close event.
  //    String whatClientSaid = thisClient.readString();
  //    if (whatClientSaid != null) {
  //      println(thisClient.ip() + "\t" + whatClientSaid);
  //      s_messageServer = "";
  //      s_messageClient = whatClientSaid;
  //      processClientCommands(whatClientSaid);
  //    }
  //  }//Client available
  //} else { //Server not aactive
  //  myBackground = color(255, 0, 0); //Red to indicate no server.
  //  background (myBackground);
  //  s_messageServer = "Server not active";
  //  s_serverStatus = "Server not active";
  //  text(s_serverStatus, 400, 10);
  //  text("Client Connection: "+s_clientStatus, 400, 20);
  //  text("Client: " + s_messageClient, 400, 40);
  //  text("Server:" + s_messageServer, 400, 50);   
  //  text("Server Keyboard Commands", 10, yInstructionLocation);
  //  printUserInstructions();
  //}
  printUserInstructions();
}//draw()
