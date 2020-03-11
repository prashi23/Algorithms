#include <iostream>
#include<stdlib.h>
#include <string.h>
#include<sstream>
using namespace std;

int main (int argc,char* argv[])
 {
 	std::string str1=argv[1];
	stringstream ss(str1);
   
   string str2;
   str2 = argv[2];
   
	size_t ndex = str1.find(str2); 
    if (ndex != string::npos) 
        cout <<(ndex+1) ; 
        else
        cout<<"0";
   
   
   return 0;
}
