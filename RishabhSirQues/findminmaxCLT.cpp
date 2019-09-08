#include<stdlib.h>
#include<iostream>
#include<sstream>
using namespace std;
int main(int argc,char* argv[])
{
	std::string str=argv[1];
	stringstream s(str);
	int i=0,a[20],b,max=0,min=0;
	while(s>>a[i])
	{
		getline(s,str,' ');
		i++;
	}
	

	b=atoi(argv[2]);
	if(b==1)
	{
		max=a[0];
		for(int j=1;j<i;j++)
		{
			if(a[j]>max)
				max=a[j];
		}
		cout<<max;
	}
	if(b==2)
	{
		min=a[0];
		for(int j=1;j<i;j++)
		{
			if(a[j]<min)
				min=a[j];
		}
		cout<<min;
	}
    return 0;
}