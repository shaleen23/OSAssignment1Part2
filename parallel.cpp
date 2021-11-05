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

int counter = 0;

void load_url()
{
    string urlLine;
    ifstream urlFile("urls.txt");

    if (urlFile.is_open())
    {
        cout << "Poggers" << endl;
    }
    else
    {
        cout << "Not pog" << endl;
        exit(-1);
    }

    while (!urlFile.eof())
    {
        urlFile >> urlLine;
        url.push_back(urlLine);
    }
    urlFile.close();
}

void createChild()
{
    pid_t pid;

    for (int i = 0; i < counter; i++)
    {
        pid = fork();
        if (pid < 0)
        {
            cerr << "No, no fork";
            exit(1);
        }

        if (pid < 0)
        {
            cout << "this is not epic" << endl;
            exit(1);
        }
        else if (pid == 0)
        {
            if (!(execlp("wget", "wget", url.back().c_str(), NULL)))
            {
                perror("execlp");
                exit(1);
            }
        }
        else
        {
            url.pop_back();
        }
    }
}

int main()
{
     vector<string> urls;

  load_url();
  createChild();  //4

  while (counter > 0) {
    wait(NULL);
    counter--;
  }

  cout << endl;
  cout<<"Complete :)"<<endl;
  return 0;
}