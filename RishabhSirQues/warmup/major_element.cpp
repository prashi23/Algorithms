#include<iostream>
#include<climits>
using namespace std;
int main(int argc,char **argv)
{
string s;
s=argv[1];
int a[10000];
int x=0;
int n=s.size();
for(int i=0;i<n;i++)
{
int num=s[i]-48;
i++;
while(s[i]!=32&&i!=n)
{
num=(num*10)+(s[i]-48);
i++;
}
a[x]=num;
x++;
}
int max=INT_MIN;
for(int i=0;i<x;i++)
{
if(a[i]>max)
max=a[i];
}
int val[max+1];
for(int i=0;i<=max;i++)
{
val[i]=0;
}
for(int i=0;i<x;i++)
{
val[a[i]]++;
}
int flag=0;
for(int i=0;i<=max;i++)
{
if(val[i]>=x/2){
cout<<i;
flag=1;
}
}
if(flag==0)
cout<<"NONE";
}


