#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include <sstream>

using namespace std;

void reverse_ar(int *ar,int n){
    for(int i=0;i<n/2;i++){
        swap(ar[i],ar[n-i-1]);
    }
}

void display(int *ar,int n){
    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
    cout<<endl;
}

int elements_together_lessK(int *ar,int n,int k){
    int c=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(ar[j]<k && ar[i]>ar[j]){
                    swap(ar[i],ar[j]);
                    c++;
            }
        }
    }
    return c;
}

void push_zero_right(int *ar,int n){
    int j=n-1;
    int c=0;
    for(int k=0;k<n;k++)
        if(ar[k]==0)
            c++;
    for(int k=0;k<n-c;k++){
        if(ar[k]==0 && ar[j]!=0){
            swap(ar[k],ar[j]);
            j--;
        }
        else if(ar[j]==0)
            j--;
    }
}

void push_zero_rt2(int *ar,int n){
    int c=0;
    for(int k=0;k<n;k++)
        if(ar[k]!=0){
            ar[c++]=ar[k];
        }
    while(c<n)
        ar[c++]=0;
}

int pivot(int *ar, int n){
    for(int i=0;i<n;i++)
        if(ar[i]<0 && ar[i+1]>=0)
            return i;
}

void neg_pos_alt(int *ar,int n){
    sort(ar,ar+n);
    int p=pivot(ar,n);
    int t;
    for(int i=1;i<n-1;i=i+2){
        int in=min(p+i,n-1);
        t=ar[in];
        for(int j=in;j>i-1;j--){
            ar[j]=ar[j-1];
        }
        ar[i]=t;
    }
}

bool comp(string a,string b){
    string ab= a.append(b);
    string ba= b.append(a);
    return ab.compare(ba) >0 ? true:false;
}

void biggest_no(int *ar,int n){
    ostringstream os;
    vector<string> arr;
    for(int i=0;i<n;i++){
       os.str("");
       os.clear();
       os<<ar[i];
       arr.push_back(os.str());
    }
    sort(arr.begin(),arr.end(),comp);
    for (int i=0; i < arr.size() ; i++ )
        cout << arr[i];
    cout<<endl;
}

int main(){
    //int ar[]={1,2,4,5,6,7,8,9,10};
    //int ar2[]={2, 7, 9, 5, 8, 7, 4};
    //int ar3[]={1, 2, 0, 0, 0, 3, 6};
    //int ar4[]={-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int ar5[]={54, 546, 548, 60};
    //reverse_ar(ar,9);
    //cout<<elements_together_lessK(ar2,7,8)<<endl;
    //push_zero_rt2(ar3,7);
    //neg_pos_alt(ar4,10);
    //display(ar4,10);
    biggest_no(ar5,4);
    return 0;
}
