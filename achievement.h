
#include <iostream>
#include "bits/stdc++.h" 
#include <fstream>

using namespace std;


void print_file() 
{ 
       string line;
       ifstream myfile ("achievements.txt");
       if (myfile.is_open())
      {
              while ( getline (myfile,line) )
           {
            cout << line << '\n';
            }
         myfile.close();
       }


  return;
}    


   