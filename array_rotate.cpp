#include <iostream>
#include <algorithm>

using namespace std;

void rotate_ar(int *ar, int n,int k){
    int temp[k];
    //left rotate
    for(int i=0;i<n+k;i++){
        if(i<k)
            temp[i]=ar[i];
        else if(i<n)
            ar[i-k]=ar[i];
        else if(i<n+k)
            ar[i-k]=temp[i-n];
    }
}

int pivot(int *ar,int n){
    for(int i=0;i<n-1;i++)      //find rotation count
        if(ar[i]>ar[i+1])
            return i;
}

int bin_search_it(int *ar,int l,int n,int val){
    while(l<=n){

        int mid= l+(n-l)/2;
        if(ar[mid]==val)
            return  mid;
        else if(ar[mid]>val)
            n=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

int sorted_rotated(int *ar,int n,int k){
    int p=pivot(ar,n);
    if(ar[0]<=k && k<=ar[p])
        return bin_search_it(ar,0,p,k);
    else
        return bin_search_it(ar,p+1,n,k);
}

void find_sum(int *ar,int n,int k){
    for(int i=0;i<n;i++){
        int t=k-ar[i];
        int y=sorted_rotated(ar,n,t);
        if(y==-1)
           continue;
        else{
            cout<<"Pair found - "<<ar[i]<<" and "<<ar[y];
            return;
        }
    }
    cout<<"PAir not found";
}

void fast_rotate(int *ar, int n,int k){
    int mod=k%n;
    for(int i=0;i<n;i++){
        cout<<ar[(mod + i)%n]<<" ";
    }
    cout<<endl;
}

void display(int *ar,int n){
    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
    cout<<endl;
}

void find_max_sum_sorted(int *ar,int n){
    int p=pivot(ar,n);
    rotate_ar(ar,n,p+1);
    display(ar,n);
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=(ar[i]*i);
    cout<<"MAx Sum of Sorted and Rotated array - "<<sum<<endl;
}

void find_index_after_rotation(int *ar,int n,int k,int r){
    int i=bin_search_it(ar,0,n,k);
    int in=i-(r%n);
    if (in>=0)
        cout<<in;
    else
        cout<<n+in;
}

int main(){
    int ar[]={1,2,4,5,6,7,8,9};
    int ar2[]={ 3, 2,1};
    //rotate_ar(ar,8,3);
    find_index_after_rotation(ar,8,4,3);
    fast_rotate(ar,8,3);

    //display(ar,8);
    //cout<<sorted_rotated(ar,8,9);
    //find_sum(ar,8,6);
    //find_max_sum_sorted(ar2,3);
    return 0;
}
