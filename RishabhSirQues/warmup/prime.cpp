#include<iostream>
#include<cstdlib>
using namespace std;
int main(int argc, char *argv[])
{
int i, flag;
int a=atoi(argv[1]),b=atoi(argv[2]);
while (a <= b)
{
flag = 0;
for(i = 2; i <= a/2; ++i)
{
if(a % i == 0)
{
flag = 1;
cout << 0 << " ";
break;
}
}
if (flag == 0)
cout << 1 << " ";
++a;
}
cout << endl;
return 0;
}

