/** LoggingToFile
 * For logging text file  
 * Appends text to the end of a text file located in the data directory, 
 * creates the file if it does not exist.
 * Can be used for big files with lots of rows, 
 * existing lines will not be rewritten
 *
 * Example usage: appendTextToFile(myLogFileName, ("Client disconnect: " + myClient.ip()));
 * General usage: appendTextToFile(myLogFileName, String);
*/

//  if (Verbose) {appendTextToFile(myLogFileName, "Client connected: " + s_clientAddress );}
 
 /* For logging text file */
import java.io.BufferedWriter;
import java.io.FileWriter;

String myLogFileName = "ServerComeAndGoes.log.txt";

void appendTextToFile(String filename, String text) {
  String myTime = (str(year()) + str(month()) +str(day()) +"_" + str(hour()) + str(minute()) + str(second()) );
  text = myTime +" " + text;
  File f = new File(dataPath(filename));
  if(!f.exists()){
    createFile(f);
  }
  try {
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(f, true)));
    out.println(text);
    out.close();
  }catch (IOException e){
      e.printStackTrace();
  }
}  

/**
 * Creates a new file including all subfolders
 */
void createFile(File f){
  File parentDir = f.getParentFile();
  try{
    parentDir.mkdirs(); 
    f.createNewFile();
  }catch(Exception e){
    e.printStackTrace();
  }
} 
