/* User Interface with keyboard*/
/* Commands to be sent to target device, the GPAD*/

/* 20221103 Simplify the KeyPress structure and move the serial ouput to end and only output on valid keys.
 * Make alarms more verbose.
 
 */

void keyPressed() {
  boolean newValidCommand = false;
  if (key!=CODED) { //Ignore ALT, CONTROL, SHIFT, UP, DOWN, LEFT and RIGHT
    //Proccess keys of UI.

    if ((key== 'a'|| (key== 'A'))) {
      newValidCommand = true;
      outString = "a0 pseudoSerialVent Testing.  All is OK.";
    }// A

    if ((key== 'b'|| (key== 'B'))) {
      newValidCommand = true;
      outString = "a1 pseudoSerialVent Testing. For your INFO.";
    }// B

    if ((key== 'c'|| (key== 'C'))) {
      newValidCommand = true;
      outString = "a2 pseudoSerialVent Testing. I found a PROB.";
    }// C

    if ((key== 'd'|| (key== 'D'))) {
      newValidCommand = true;
      outString = "a3 pseudoSerialVent Testing. This is a first WARN.";
    }// D


    if ((key== 'e') || (key== 'E')) {
      newValidCommand = true;
      outString = "a4 pseudoSerialVent Testing. This is becoming CRIT.";
    }// E


    if ((key== 'f') || (key== 'F')) {
      newValidCommand = true;
      outString = "a5 pseudoSerialVent Testing. It is time to PANIC.";
    }// E


    if ((key== 'h'|| (key== 'H'))) {
      newValidCommand = true;
      //Requst the help message
      outString = "h";
    }// H

    if ((key== 's'|| (key== 'S'))) {
      newValidCommand = true;
      //Set mute case true
      outString = "s";
    }// S

    if ((key== 'u'|| (key== 'U'))) {
      newValidCommand = true;
      //Un mute
      outString = "u";
    }// U

    if ( (key== 'X') || (key== 'x')) {
      //Exit this program     
      println("Writing 'a0' to serial port to clear alarms .");
      myPort.write("a0\n");  //set alarms off.
      println("Writing 'u' to serial port to mute .");
      myPort.write("u\n");  //mute
      println("Good buy.");
      appendTextToFile(myLogFileName, ("Your log is terminated."));
      exit();
    }// X

    if (newValidCommand == true) {
      print("To GPAD: ");
      println(outString);
      myPort.write(outString);

      myBackground = color(255, 0, 0); //Red indicated command sent.
      timeSerialSent = millis();
      timeSerialReceived = timeSerialSent - 1;
      newValidCommand = false;
    }
  }// end note key coded
}// User Interface keyPressed() 


/** Mouse functions 
 *
 * /brief Send server messages through socket. 
 * The ST365 Status quiry on left and Hello world on right. 
 */

//Mouse press to send ST365 command or text.
void mousePressed() {
  //  if (myServer.active() == true){  
  if (myServerRunning) {  
    if (mouseButton == LEFT) {  
      println(">04");
      myServer.write(">04\r");    
      s_messageServer = ">04\r";
      s_messageClient = "";
    } else {
      println(">Hello world");
      myServer.write(">Hello from server.\n\r");
      s_messageServer = ">Hello from server.\n\r";
      s_messageClient = "";
    }
  }//Active
  else {
  }
} //MousePressed

void printUserInstructions() {
  /*User menu*/
  textAlign(LEFT); 
  textFont(fBig);
  text("KEYBOARD COMMANDS:", 10, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
  textFont(f);  //Back to regular
  text("A or a: Sets Alarm A0", 20, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
  text("B or b: Sets Alarm A1", 20, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
  text("C or c:Sets Alarm A2", 20, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
  text("D or d:  Sets Alarm A3", 20, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
  text("E or e:  Sets Alarm A4", 20, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
  text("F or f:  Sets Alarm A5", 20, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
  text("S or s: will Silence (mute) buzzer", 20, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
  text("U or u: will Unmute buzzer", 20, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
  text("X or x: will eXit the program", 20, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
}
