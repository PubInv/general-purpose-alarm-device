void serialEvent(Serial p) { 
  inString = p.readString(); 
  print("Serial input: ");
  println(inString);
} 
