#include<bits/stdc++.h>

using namespace std;


void display(int *ar,int n){
    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
    cout<<endl;
}

void alternative_sorting(int *ar,int n){
    sort(ar,ar+n);
    int j;
    if(n%2==0)
        j=n/2;
    else
        j=(n/2)+1;
    for(int i=0;i<j;i++){
        if(i!=n/2)
            cout<<ar[n-i-1]<<" "<<ar[i]<<" ";
        else if(i==n/2)
            cout<<ar[i];
    }
    cout<<endl;
}
/*
bool com(pair <int , int > a,pair <int , int > b){
    return (a->second < b->second);
}

void difference_sort(int *ar, int n, int k){
    int t;
    map <int , int > s;
    for(int i=0;i<n;i++){
        t= abs(ar[i]-k);
        s.insert(s[ar[i]]=t);
    }
    sort(s.begin(), s.end(), com);
    map<int, int>:: iterator p;
    for (p = s.begin(); p != s.end(); p++)
        cout<<p.first<<" ";
}
*/

void wave_sort(int *ar, int n){
    sort(ar,ar+n);
    for(int i=0;i<n-1;i+=2){
        swap(ar[i],ar[i+1]);
    }
}

void merge_sorted(int *ar1,int n1,int *ar2,int n2){
    int n=n1+n2;
    int ar[n];
    int i=0,j=0,k=0;
    while(n--){
        if(ar1[i]==ar2[j] && i<n1 && j<n2){
            ar[k]=ar1[i];
            k++;
            ar[k]=ar1[i];
            k++; i++; j++;
            n--;
        }
        else if(ar1[i]<ar2[j] && i<n1 && j<n2){
            ar[k]=ar1[i];
            i++; k++;
        }
        else if(ar1[i]>ar2[j] && i<n1 && j<n2){
            ar[k]=ar2[j];
            j++; k++;
        }
        else if(i<n1 && i>j){
                ar[k]=ar1[i];
                k++;
                i++;
        }
        else if(j<n2 && i<j){
                ar[k]=ar2[j];
                k++;
                j++;
        }
    }

    cout<<"i="<<i<<"j="<<j<<"k="<<k<<endl;
    display(ar,n1+n2);
}

void intersection(int *ar1,int *ar2,int n1,int n2){
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(ar1[i]==ar2[j]){
            cout<<ar1[i]<<" ";
            i++;    j++;
        }
        else if(ar1[i]<ar2[j]){
            i++;
        }
        else
            j++;
    }
}


int main(){
    int ar[]={10, 9,0, 49, 2, 1, 5, 23};
    int ar1[]={1,3,5,8,11,14,18};
    int ar2[]={2,5,8,11};

    //alternative_sorting(ar,7);
    //wave_sort(ar,7);
    //merge_sorted(ar1,7,ar2,4);
    intersection(ar1,ar2,7,4);
    //display(ar,7);
    return 0;
}
