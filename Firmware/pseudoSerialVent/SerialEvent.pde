/*Event service.
 Writes serial buffer received into global 'inString'
 */
void serialEvent(Serial p) { 
  inString = p.readString(); 
  String myTime = (str(year()) + str(month()) +str(day()) +"_" + str(hour()) + str(minute()) + str(second()) );
  print(myTime);
  print(" Serial received: ");
  print(inString);
  myBackground = color(0, 0, 0); //Black indicated serial received.
  timeSerialReceived = millis();
  checkInString();
} 


/*Check the inString variable 
 Sheck for the string 'onPress' to indicate the Mute button has been pressed.
 Check for the DUT state 'Muted: YES' or 'Muted: NO'. Sets flag dutMuted. 
 */
void checkInString() {

  String[] m1 = match(inString, "onPress");
  if (m1 != null) {  // If not null, then a match was found
    // This will print to the console, since a match was found.
    println("Found a match in '" + trim(inString) + "'");
  }
  m1 = match(inString, "Muted: YES");
  if (m1 != null) {
    dutMuted = true;
    println("State of '" + trim(inString) + "'");
  } 
  m1 = match(inString, "Muted: NO");
  if (m1 != null) {
    dutMuted = false;
    println("State of '" + trim(inString) + "'");
  } 
  //else {
  //  println("No match found in '" + trim(inString) + "'");
  //}
  
}// end checkInString
