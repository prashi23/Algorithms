#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;
int a; 
int count[30]={0};
ofstream fout;
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];   
    int i = (low - 1); 
  	int temp,t1;
    for (int j = low; j <= high- 1; j++) 
    {  	
        if (arr[j] <= pivot) 
        { 
            i++;   
           temp= arr[i] ;
		   arr[i]=arr[j]; 
		   arr[j]=temp;
        } 
    }
    	t1=arr[high];
        for(int n=high;n>i+1;n--)
        {
        	arr[n]=arr[n-1];
		}
		arr[i+1]=t1;
		count[i+1]=1;	
 return (i + 1); 
} 
void quickSort(int arr[], int low, int high) 
{  int i;
    if (low <= high) 
    {
        int pi = partition(arr, low, high); 
 
      for( i=0;i<a-1;i++)
      {
      	if(count[i]!=1) 
		  {fout<<arr[i]<<",";
		  }
      	else {
      		fout<<"("<<arr[i]<<"),";
        }
	  }
	  if(count[i]!=1) 
	  {
	  fout<<arr[i];
	  }
      else
	  {
	  fout<<"("<<arr[i]<<")";
	  }
	  fout<<endl;
      quickSort(arr, low, pi - 1); 
      quickSort(arr, pi + 1, high);   
    }   
} 
int main(int argc,char** argv)
 { 
    ifstream fin;
    string str;
    int arr[100];
    int j;
	a=0; 
    fin.open(argv[1]); 
    fout.open(argv[2]); 
    if(!fin)
	{
		exit(1);
	}
	 if(!fout)
	{
		exit(1);
	}
  	
	while(fin>>arr[a]) {
  		getline(fin, str ,' ');
			a++;
		}
	for(  j=0;j<a-1;j++)
    { 	 fout<<arr[j]<<","; 
	}
 	 fout<<arr[j]<<endl;
  	//call quicksort 
 	 quickSort(arr,0,a-1);	
	//      
	for(j=0;j<a-1;j++)
   	{
   	 fout<<arr[j]<<","; 
    }
	fout<<arr[j];
    fin.close();
    fout.close();
 	return 0;
}