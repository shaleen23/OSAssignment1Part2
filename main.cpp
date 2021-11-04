#include <iostream> 
#include <unistd.h> 
#include <sys/wait.h>
#include <string> 
#include <vector>
#include <fstream> 
#include <stdlib.h>

using namespace std; 

int main()
{
    pid_t pid; //create process ID 

    int i = 0; //create a counter to iterate through list
    ifstream fileInput; 

    vector <string> urlList; //create a vector of type string called urlList to store all the urls 
    string str;
    while(getline(fileInput, str)) //while there are strings in the file, add them to the vector 
    {
        urlList.push_back(str);
    }
  pid = fork(); //set process ID to fork

  for(int i = 0; i< urlList.size(); i++) //iterate through the vector 
  {
      if(pid == -1) //if the process ID is Null, exit the code 
      {
          printf("Process failed");
          return 0;
      }
      else if(pid == 0) //if the process ID value is 0, replace the current process image with a new process image 
      {
        execlp("/usr/bin/wget", "wget", urlList[i] ,NULL);  
      }
  }  
}