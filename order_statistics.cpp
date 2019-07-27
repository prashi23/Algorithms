#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>


using namespace std;

int kadane(int *ar,int n){
    int maxsofar=0,maxend=0;
    for(int i=0;i<n;i++){
        maxsofar+=ar[i];
        if(maxsofar > maxend){
            maxend=maxsofar;
        }
        else if(maxsofar< 0){
            maxsofar =0;
        }
    }
    return maxend;
}

void max_sum_comb(int *ar1,int *ar2, int n, int k){
    sort(ar1,ar1+n);
    sort(ar2,ar2+n);
    int i=n-1,j=n-1,m=0;
    while(m!=k){
        if(ar1[i]>=ar2[j]){
            cout<<ar1[i]+ar2[j]<<" ";
            j--;
            m++;
        }
        else if(ar1[i]< ar2[j]){
            cout<<ar1[i]+ar2[j]<<" ";
            i--;
            m++;
        }
    }
}

void min_sum_comb(int *ar1, int *ar2, int n, int k){
    sort(ar1,ar1+n);
    sort(ar2,ar2+n);
    int i=0,j=0,m=0;
    while(m!=k){
        if(ar1[i]<= ar2[j]){
            cout<<"["<<ar1[i]<<"],["<<ar2[j]<<"] sum - ";
            cout<<ar1[i]+ar2[j]<<"\n";
            j++;
            m++;
        }
        else if(ar1[i]>ar2[j]){
            cout<<"["<<ar1[i]<<"],["<<ar2[j]<<"] sum - ";
            cout<<ar1[i]+ar2[j]<<"\n";
            i++;
            m++;
        }
    }
}

void k_nonoverlap_sum(int *ar, int n, int k){
   for(int i=0;i<k;i++){
   int s=0,start=0,e=0;
   int maxsofar=0,maxend=INT_MIN;
   for(int j=0;j<n;j++){
        maxsofar+=ar[j];
        if(maxsofar > maxend){
            maxend =maxsofar;
            start=s;
            e=j;
        }
        else if(maxsofar <0){
            maxsofar =0;
            s=j+1;
        }
   }
    cout<<"STart - "<<start<<" End - "<<e<<" Sum - "<<maxend<<endl;
    for(int h=start; h<=e; h++)
        ar[h]=INT_MIN;
   }
}

void max_min(int *ar,int n){
    int max_el=ar[0],min_el=ar[0];
    for(int i=1;i<n;i++){
        if(ar[i]>max_el)
            max_el=ar[i];
        if(ar[i]<min_el)
            min_el =ar[i];
    }
    cout<<"MAX - "<<max_el<<" MIN - "<<min_el;
}

bool comp(pair<int ,int > a, pair<int , int > b){
    return (a.second >b.second ? true: false);

}

void Kmax_freq(int *ar,int n,int k){
    unordered_map<int , int> freq;
    for(int i=0;i<n;i++){
        freq[ar[i]]++;
    }
    vector <pair<int ,int> > f(freq.begin(), freq.end());
    sort(f.begin(),f.end(), comp);
    for(int i=0;i<k;i++){
        cout<<f[i].first<<" "<<f[i].second<<"\n";
    }
}

int main(){
    //int ar7[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int ar[]={3, 1, 4, 4, 5, 2, 6, 1};
    int ar1[]={1, 7, 11};
    int ar2[]={2, 4, 6};
    //cout<<kadane(ar7,8);
    //k_nonoverlap_sum(ar,10,3);
    //max_min(ar,10);
    Kmax_freq(ar,8,2);
    //min_sum_comb(ar1, ar2,3,3);
    return 0;
}
