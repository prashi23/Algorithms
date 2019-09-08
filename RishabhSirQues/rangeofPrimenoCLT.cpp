#include<iostream>
#include<cstdlib>
using namespace std;
int main(int argc, char *argv[])
{
int i, flag;
int x = atoi(argv[1]),y = atoi(argv[2]);
while (x <= y)
{
flag = 0;
for(i = 2; i <= x/2; ++i)
{
if(x % i == 0)
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
