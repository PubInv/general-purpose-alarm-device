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

void checkInString() {

  String[] m1 = match(inString, "onPress");
  if (m1 != null) {  // If not null, then a match was found
    // This will print to the console, since a match was found.
    println("Found a match in '" + trim(inString) + "'");
  } else {
    println("No match found in '" + trim(inString) + "'");
  }

}// end checkInString
