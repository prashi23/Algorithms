#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

int main(int argc, char** argv){
	char *file1= argv[1], *file2=argv[2];
	ifstream infile;
	ofstream outfile;
	infile.open(file1);
	outfile.open(file2);
	if(!file1 || !file2){
		cout<<"unable to open file";
	}
	
	int nums[100],k=0,j,i,p;
	string str;
	while(infile >> nums[k]){
		getline(infile,str,' ');
		k++;
	}
		
	infile.close();
	infile.open(file1);

	for( i=0; i<k; i++)
	{
		
		p=nums[i];
		j=i-1;
	
		while(j>=0 && nums[j]>p)
		{
			nums[j+1]=nums[j];
			j=j-1;
		}
		nums[j+1]=p;
		for(int g=0;g<k;g++)
		{
			outfile<<nums[g]<<" ";
		}
		outfile<<"\n";
		}	
	

	
	infile.close();
	outfile.close();
	return 0;
}

