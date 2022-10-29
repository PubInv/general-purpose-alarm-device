/* User Interface with keyboard*/
/* Commands to be sent to target device, the GPAD*/

void keyPressed() {
  if (key!=CODED) { //Ignore ALT, CONTROL, SHIFT, UP, DOWN, LEFT and RIGHT

    //Proccess keys of UI.



    if ((key== 'a'|| (key== 'A'))) {
      outString = "a0";
      println("Writing 'a0' to serial port.");
      myPort.write(outString);  //
    }// A

    if ((key== 'b'|| (key== 'B'))) {
      outString = "a1";
      println("Writing 'a1' to serial port.");
      myPort.write(outString);  //
    }// B

    if ((key== 'c'|| (key== 'C'))) {
      outString = "a2";
      println("Writing 'a2' to serial port.");
      myPort.write(outString);  //
    }// C

    if ((key== 'd'|| (key== 'D'))) {
      outString = "a3";
      println("Writing 'a3' to serial port.");
      myPort.write(outString);  //
    }// D


    if ((key== 'e') || (key== 'E')) {
      outString = "a4";
      println("Writing 'a4' to serial port.");
      myPort.write(outString);  //
    }// E


    if ((key== 'f') || (key== 'F')) {
      outString = "a5";
      println("Writing 'a5' to serial port.");
      myPort.write(outString);  //
    }// E


    if ((key== 'h'|| (key== 'H'))) {
      //Requst the help message
      println("Writing 'h\\n' to serial port.");
      myPort.write("h");  //help
      myPort.write("h\n");  //help
    }// H

    if ((key== 's'|| (key== 'S'))) {
      //Set mute case true
      outString = "s";          
      println("Writing 's' to serial port.");
      myPort.write(outString);  //     
    }// S

    if ((key== 'u'|| (key== 'U'))) {
      //Un mute
      outString = "u";
      println("Writing 'u' to serial port.");
      myPort.write(outString);  //
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
  text("S or s: will UN mute buzzer", 20, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
  text("U or u: will mute buzzer", 20, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
  text("X or x: will EXit the program", 20, yInstructionLocation); 
  yInstructionLocation += yInstructionNextLine;
}
