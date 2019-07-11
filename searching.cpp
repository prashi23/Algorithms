#include <iostream>
#include <cmath>
using namespace std;


void display(int *ar,int n){
    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
}


//O(log N)

int bin_search(int *ar,int l,int n,int val){
    if(l<=n){
        int mid= l +(n-l)/2;
        if(ar[mid]==val)
            return mid;
        else if(ar[mid]>val)
            return bin_search(ar,l,mid-1,val);
        else
            return bin_search(ar,mid+1,n,val);
    }
    return -1;
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

//O(root(N))

int jump_search(int *ar,int N,int val){
    int step = sqrt(N);
    int prev=0;
    while(ar[min(N,step)]< val){
        prev=step;
        step+=sqrt(N);
    }
    for(int i=prev;i<=step;i++){
        if(ar[i]==val)
            return i;
    }
    return -1;
}

//O(log log N) //max- O(N) - better for uniformly distributed array

int interpolation_search(int *ar,int N,int val){
    int lo=0;
    int hi=N-1;

    while(lo<=hi && ar[lo]<=val && ar[hi]>=val){
        int pos = lo + (double((hi-lo)*(val -ar[lo])))/(ar[hi]-ar[lo]);
        if(hi==lo){
            if(ar[lo]==val)
                return lo;
            else
                return -1;
        }
        if(ar[pos]==val)
            return pos;

        if(ar[lo]>val)
            lo=pos-1;
        else
            hi=pos+1;
    }
    return -1;
}

//O(log N)

int exponential_search(int *ar, int N,int val){

    int step=1;
    while(step<N && ar[step]<=val){
        step=step*2;
    }
    return bin_search(ar,step/2,min(step,N),val);
}

//O(log3 N) - seems lesser than binary search but is more - 4log3(n) > 2log2(n)

int ternary_search(int *ar, int l,int n,int val){
    while(l<=n){
        int mid1= l+(n-l)/3;
        int mid2= mid1+(n-l)/3;

        if(ar[mid1]==val)
            return mid1;
        else if(ar[mid2]==val)
            return mid2;
        else if(ar[mid1]>val)
            return ternary_search(ar,l,mid1-1,val);
        else if(ar[mid2]<val)
            return ternary_search(ar,mid2+1,n,val);
        return ternary_search(ar,mid1+1,mid2-1,val);
    }
    return -1;
}


int main(){
	int ar[20];
    int N,ls;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>ar[i];
    }
    //display(ar,N);
    //cout<<"\nbinary search - ";
    cin>>ls;
    //cout<<endl<<bin_search(ar,0,N,ls);
    cout<<endl<<"exponential search - "<<ternary_search(ar,0,N,ls);
    return 0;
}
