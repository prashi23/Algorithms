#include<bits/stdc++.h>

using namespace std;

void mergeSort(int*, int, int);
void merge(int*, int, int, int);

int main(int argc, char** argv){
	int size=atoi(argv[1]);
	string val=argv[2];
	stringstream ss(val);
	int num[size],i=0;
	while(ss>>num[i]){
		getline(ss,val,' ');
		i++;
	}

	mergeSort(num,0,size-1);
	for(i=0;i<size;i++)
		cout<<num[i]<<" ";
	return 0;
}

void mergeSort(int *arr, int left, int right){
	if(left<right){
		int mid=(left+right)/2;
		mergeSort(arr,left,mid);
		mergeSort(arr,mid+1,right);
		merge(arr,left,right,mid);
	}
}

void merge(int *arr, int left, int right, int mid){
	int i, j, k, temp[right-left+1];
	i = left;
	k = 0;
	j = mid + 1;
	while (i <= mid && j <= right){  // Merge the two parts 
		if (arr[i] < arr[j]){
			temp[k] = arr[i];
			k++;
			i++;
		}
		else{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}

	while (i <= mid){
		temp[k] = arr[i];
		k++;
		i++;
	}
	while (j <= right){
		temp[k] = arr[j];
		k++;
		j++;
	}
	for (i = left; i <= right; i++){
		arr[i] = temp[i-left];
	}
}
