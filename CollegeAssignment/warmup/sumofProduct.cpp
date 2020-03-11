#include<iostream>
#include<stdlib.h>
using namespace std;
int main(int argc,char* argv[])
{
	int a,b,c=0,p=0,r,q,s=0,pr=1,a1,b1;
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	a1=a;
	b1=b;
	while(a>0)
	{
		r=a%10;
		c++;
		a=a/10;
	}

	while(b>0)
	{
		r=b%10;
		p++;
		b=b/10;
	}
	
	if(c==p)
	{
		while(a1>0 && b1>0)
	   {
		   r=a1%10;
		   q=b1%10;
		   pr=r*q;
		   s=s+pr;
		   a1=a1/10;
		   b1=b1/10;	
		}
		cout<<s;
	}
	else
	cout<<"-1";
}
