#include<iostream>
#include<cstdlib>
using namespace std;
int func(int n , int r)
{
	if (n==0||r==0)
       return 1;
    return func(n-1,r)+func(n-1,r-1);
    
}

int main(int argc,char **argv)
{

	int n=atoi(argv[1]),r=atoi(argv[2]);
	cout<<func(n,r);

}
