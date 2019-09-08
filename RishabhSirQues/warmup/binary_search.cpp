#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
int fun(int *a,int n,int start,int end,int ele,int&index,int&count){
    int x=-1,y=-1;
if(start>end)
    return -1;
int mid=(start+end)/2;
 count++;
if(a[mid]==ele){
    index=mid;
    return 1;
}
    if(ele>a[mid])
 x=fun(a,n,mid+1,end,ele,index,count);
 else if(ele<a[mid])
 y=fun(a,n,start,mid-1,ele,index,count);
 if(x==-1&&y==-1)
    return -1;
 else
    return 1;
}
int main(int argc,char **argv)
{
    int a[10000];
    int k=1;
ifstream inf(argv[1]);
string b;
inf>>b;
int size=b.size();
for(int i=0;i<size;i++)
{
    int num=b[i]-48;
i++;
    while(b[i]!=44&&i!=size)
    {
num=(num*10)+b[i]-48;
i++;
    }
    a[k]=num;
    k++;
}
int n=k;
sort(a+1,a+n);
k=0;
int value[10000];
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

ofstream outf(argv[2]);
for(int i=0;i<=k-1;i++)
{
    int count=0,index=-1;
int ans=fun(a,n,1,n-1,value[i],index,count);
if(ans==1)
outf<<value[i]<<" found at position "<<index<<" after "<<count<<" comparisons"<<endl;
    if(ans==-1)
outf<<value[i]<<" not found"<<endl;
}



}

