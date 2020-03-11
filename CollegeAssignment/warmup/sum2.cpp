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
	
	int sum=0,nums[100],k=0;
	string str;
	while(infile >> nums[k]){
		getline(infile,str,' ');
		k++;
	}
		
	infile.close();
	infile.open(file1);
	
	getline(infile,str,'\n');
	infile>>sum;
	
	for(int i=0; i<=k; i++){
		for(int j= i+1; j<=k; j++)
			if(nums[i]+nums[j] == sum)
				outfile << nums[i]<<","<< nums[j]<<"\n";
	}
	infile.close();
	outfile.close();
	return 0;
}
