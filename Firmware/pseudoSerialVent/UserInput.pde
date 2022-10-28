/* User Interface with keyboard*/

void keyPressed() {
  //Proccess keys of UI.
  
  if ((key== 'a'|| (key== 'A'))){
     //Socket Active Test
     println("Testing for active server.");
     if (myServer.active()== true) {
       println("Server active.");  
       } else {
       println("Server not active.");
         }
   }// A
 
  if ((key== 'd'|| (key== 'D'))){
     //Disconnect Client Socket  ???thisClient???   
     println("Disconnecting Client socket. Server: " + myServer + ", Client: " + myClient);
     try{
        //do something that might throw NPE
        myServer.disconnect(myClient);
        println("I did it. I got a Non null pointer and disconnected that client.");
     }
     catch(NullPointerException npe){
        //uh oh, an NPE happened
        println("Client disconnect exception, I got a null pointer all right.");
     } //disconnect client();
  }//D
  
    if ((key== 'e') || (key== 'E') || (key== 'X') || (key== 'x')){
     //Stop Clients, Server and then Exit this program     
     try {
       myServer.disconnect(myClient);
       println("Client disconnect.");
     } catch (Exception npe)
     {
       println("Clien Disconnect exception with: " + npe);
     }
     try {
       myServer.stop();
       println("Server Stop");
     } catch (Exception npe) 
       {
       println("Server Stop exception with: " + npe);
       }
     println("Good buy.");
//     String endTime = (str(year()) + str(month()) +str(day()) +"_" + str(hour()) + str(minute()) + str(second()) );
     appendTextToFile(myLogFileName, ("Your log is terminated."));
     exit();
   }// E
  
  if (((key =='S') && (myServerRunning== true)) || ((key =='s') && (myServerRunning== true))){
     //stop Socket
     println("Stoping Server.");
     myServerRunning = false;
     myServer.stop();
     myServer = null;
     //exit();
  }//s

  if (((key =='g') && (myServerRunning== false)) || ((key =='G') && (myServerRunning== false)) ){
     println("Go to start new server.");
     myServer = new Server(this, MY_PORT); // Starts a server   
     s_messageServer= "New server "; 
     s_serverStatus = "New server running";
     myServerRunning = true;
     myBackground = color(0,0,0); //Set to black when server started
  }//S

 
}// User Interface keyPressed() 


/** Mouse functions 
 *
 * /brief Send server messages through socket. 
 * The ST365 Status quiry on left and Hello world on right. 
 */

//Mouse press to send ST365 command or text.
void mousePressed() {
//  if (myServer.active() == true){  
  if (myServerRunning){  
    if (mouseButton == LEFT){  
    println(">04");
    myServer.write(">04\r");    
    s_messageServer = ">04\r";
    s_messageClient = "";
    }
    else {
      println(">Hello world");
      myServer.write(">Hello from server.\n\r");
      s_messageServer = ">Hello from server.\n\r";
      s_messageClient = "";
    }
  }//Active
  else{
  }
  
} //MousePressed

void printUserInstructions(){
    /*User menu*/
    textAlign(LEFT); 
    textFont(fBig);
    text("KEYBOARD COMMANDS:", 10, yInstructionLocation); yInstructionLocation += yInstructionNextLine;
    textFont(f);  //Back to regular
    text("A or a: returns server Active status", 20, yInstructionLocation); yInstructionLocation += yInstructionNextLine;
    text("D or d:  commands Disconnect client socket", 20, yInstructionLocation); yInstructionLocation += yInstructionNextLine;
    text("E or e or X or x: will EXit the program", 20, yInstructionLocation); yInstructionLocation += yInstructionNextLine;
    text("G or g: to Go with a new socket server", 20, yInstructionLocation); yInstructionLocation += yInstructionNextLine;
    text("S or s: will Stop the socket server", 20, yInstructionLocation); yInstructionLocation += yInstructionNextLine;
}
