#include<iostream>
using namespace std;
int fun(int *a,int n){
int best=0,curr=0;
for(int i=0;i<n;i++)
{
curr=curr+a[i];
if(curr>best)
best=curr;
if(curr<0)
curr=0;
}
return best;
}
int main(int argc,char**argv)
{
string s;
s=argv[1];
int a[10000];
int k=0;
int n=s.size();
int flag=0;
for(int i=0;i<n;i++)
{
int z=s[i];
if(z==45){
    flag=1;
i++;
}
int num=s[i]-48;
i++;
while(s[i]!=32&&i!=n)
{
num=(num*10)+(s[i]-48);
i++;
}
if(flag==1){
a[k]=(-1*num);
flag=0;
k++;
}
else{
a[k]=num;
k++;
}
}

int ans=fun(a,n);
cout<<ans;
}

