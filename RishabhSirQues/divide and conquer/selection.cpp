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
	
	int index,nums[100],k=0,j,i,p,temp;
	string str;
	while(infile >> nums[k]){
		getline(infile,str,' ');
		k++;
	}
		
	infile.close();
	infile.open(file1);
	
	getline(infile,str,'\n');
	infile>>index;
	
	for( i=0; i<k; i++){
		p=i;
	    for(j=i+1;j<k;j++)
			if(nums[j]<nums[p])
			   p=j;
				temp=nums[p];
				nums[p]=nums[i];
				nums[i]=temp;		
	}
	for(i=0;i<k;i++)
	{
		if(i==index)
		outfile<<nums[i-1];
	}
	
	
	infile.close();
	outfile.close();
	return 0;
}

