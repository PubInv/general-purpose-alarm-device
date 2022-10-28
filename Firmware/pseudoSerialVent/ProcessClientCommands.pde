/* Server Commands simulating ST365 */

void processClientCommands(String whatClientSaid) {

  if (whatClientSaid.startsWith(">03")) {
    String myReply = "#0304\r";
    myServer.write(myReply);
    println("Reply with:" + myReply);
  }// Client sent >03.

  if (whatClientSaid.startsWith(">04")) {
    String myReply = "#040000000200000000000000000000019000\r";
    myServer.write(myReply);
    s_messageServer = myReply;
    s_messageClient = ">04";
    println("Reply with:" + myReply);
  }
  if (whatClientSaid.startsWith(">05")) {
    String myReply = "#05000A\r";
    myServer.write(myReply);
    println("Reply with:" + myReply);
  }// Client sent >05.

  if (whatClientSaid.startsWith(">06")) {
    String myReply = "#0600000000816D000300002000\r";
    myServer.write(myReply);
    println("Reply with:" + myReply);
  }// Client sent >06.

  if (whatClientSaid.startsWith(">09")) {
    String myReply = "#0901\r";
    myServer.write(myReply);
    println("Reply with:" + myReply);
  }// Client sent >09.

  if (whatClientSaid.startsWith(">16")) {
    String myReply = "#1604\r";
    myServer.write(myReply);
    println("Reply with:" + myReply);
  }// Client sent >16.

  if (whatClientSaid.startsWith(">17")) {
    String myReply = "#1703200320032005\r";
    myServer.write(myReply);
    println("Reply with:" + myReply);
  }// Client sent >17.

  if (whatClientSaid.startsWith(">19")) {
    /*No action*/
  }// Client sent >19.

  if (whatClientSaid.startsWith(">20")) {
    String myReply = "#2000010001000A00010001000B00010001000A00010001000A\r";
    myServer.write(myReply);
    println("Reply with:" + myReply);
  }// Client sent >20.

  if (whatClientSaid.startsWith(">22")) {
    String myReply = "#220078007803E807\r";
    myServer.write(myReply);
    println("Reply with:" + myReply);
  }// Client sent >22.

  if (whatClientSaid.startsWith(">70")) {
    String myReply = "#7000\r";
    myServer.write(myReply);
    println("Reply with:" + myReply);
  }// Client sent >70.
}//Not null from client
