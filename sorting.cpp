#include <iostream>

using namespace std;

void bubblesort(int *ar,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++)
            if(ar[j+1]<ar[j])
                swap(ar[j],ar[j+1]);
    }
}

void selectionsort(int *ar,int n){
    for(int i=0;i<n;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(ar[j]>ar[min_index])
                min_index=j;
                swap(ar[min_index],ar[j]);
        }
    }
}

void display(int *ar,int n){
for(int i=0;i<n;i++)
    cout<<ar[i]<<" ";
cout<<endl;
}

int main(){
    int n;
int ar[10];
cin>>n;
for(int i=0;i<n;i++){
    cin>>ar[i];
}
display(ar,n);
selectionsort(ar,n);
display(ar,n);
    return 0;
}
