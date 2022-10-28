# ServerComeAndGoes
A Processing network program, A Socket Server which can be stopped and started and can force client disconnect with by keyboard single keys.

Developed with a client program as a template for my work with wireless communication chips where I have the same problem 
to solve (a client connecting to a server which may come and go). By solving the problem in Proccessing I hope to work faster 
and have the advantage that I can put Wireshark on the network transactions to see how I am doing.

Uses the Processing network library. Opens a socket (Ip address and port) for serial communication.

If you first run this project and before a client connects it brings up a black background window. Then when a client connects
the window changes becomes lighter and text message in the window identifes the connection status

Single key presses change the connection status or exit.

Left and Righ Mouse presses send some text to the client.

The server responds to fixed client messages with a fixed message of it's own. 
