#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std; 

vector<string> url;

void load_url()
{
  string urlLine;
  ifstream urlFile("urls.txt");
  
  if(urlFile.is_open())
  {
    cout<<"Poggers"<<endl;
  }
  else
  {
    cout<<"Not pog"<<endl;
    exit(-1);
  }

  while(!urlFile.eof())
  {
    urlFile>>urlLine;
    url.push_back(urlLine);
  }
  urlFile.close();
}


void createChild()
{
  pid_t pid;
  pid = fork();
  
  if(pid<0)
  {
    cout<<"this is not epic"<<endl;
    exit(1);
  }
  else if(pid == 0)
  {
    if(!(execlp("wget", "wget", url.back().c_str(), NULL)))
    {
      perror("execlp");
      exit(1);
    }
  }
}



int main()
{
  load_url();
  createChild();
  wait(NULL);
  url.pop_back();
  createChild();
  wait(NULL);
  return 0;
}



/*
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
*/
