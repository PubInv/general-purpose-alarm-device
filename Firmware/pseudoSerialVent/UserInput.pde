/* User Interface with keyboard*/
/* Commands to be sent to target device, the GPAD*/

void keyPressed() {
  if (key!=CODED) { //Ignore ALT, CONTROL, SHIFT, UP, DOWN, LEFT and RIGHT

    //Proccess keys of UI.



    if ((key== 'c'|| (key== 'C'))) {
      //foo
      println("Writing '*CLS\\n' to serial port.");
      myPort.write("*CLS\n");  //Clear status command
    }// C

    if ((key== 'e') || (key== 'E') || (key== 'X') || (key== 'x')) {
      //Exit this program     
      println("Good buy.");
      appendTextToFile(myLogFileName, ("Your log is terminated."));
      exit();
    }// E

    if ((key== 'h'|| (key== 'H'))) {
      //Requst the help message
      println("Writing 'h\\n' to serial port.");
      myPort.write("h");  //help
      myPort.write("h\n");  //help
    }// H

    if ((key== 's'|| (key== 'S'))) {
      //Set mute case true
      println("Writing 's' to serial port.");
      myPort.write("s\n");  //mute
    }// S

    if ((key== 'u'|| (key== 'U'))) {
      //Un mute
      println("Writing 'u' to serial port.");
      myPort.write("u\n");  //unmute
    }// U
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
  text("A or a: returns server Active status", 20, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
  text("D or d:  commands Disconnect client socket", 20, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
  text("E or e or X or x: will EXit the program", 20, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
  text("G or g: to Go with a new socket server", 20, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
  text("S or s: will Stop the socket server", 20, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
}
