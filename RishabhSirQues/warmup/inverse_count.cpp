#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(int argc,char **argv)
{
ifstream inf(argv[1]);
int value[10000];
int k=0;
while(inf)
{
    string b;
    inf>>b;
    int size=b.size();
    b=b+" ";
for(int i=0;i<size;i++)
    {
      int num=b[i]-48;
i++;
        while(b[i]!=32)
        {
num=(num*10)+b[i]-48;
i++;
        }
        value[k]=num;
        k++;
    }
}

int n=k;
ofstream outf(argv[2]);
for(int i=0;i<n;i++)
{
for(int j=i+1;j<n;j++)
    {
        if(value[i]>value[j])
outf<<value[i]<<","<<value[j]<<endl;
    }
}
}

