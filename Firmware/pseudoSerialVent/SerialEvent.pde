void serialEvent(Serial p) { 
  inString = p.readString(); 
  String myTime = (str(year()) + str(month()) +str(day()) +"_" + str(hour()) + str(minute()) + str(second()) );
  print(myTime);
  print(" Serial received: ");
  print(inString);
  myBackground = color(0, 0, 0); //Black indicated serial received.
  timeSerialReceived = millis();
} 
