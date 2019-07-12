/* Searching problems on geeksforgeeks array*/


#include <iostream>

using namespace std;

void delete_array(int *ar, int &n,int k){
    for(int i=0;i<n;i++){
        if(ar[i]==k){
            for(int j=i;j<n-1;j++)
                ar[j]=ar[j+1];
                n--;
            return;
        }
    }
}

void insert_sorted(int *ar, int n, int d){
    for(int i=0;i<n-1;i++){
        if(ar[i]>=d){
            for(int j=n;j>i-1;j--){
                ar[j]=ar[j-1];
            }
            ar[i]=d;
            break;
        }
    }
}

int bin_search(int *ar,int s,int n, int k){
    while(s<=n){
        int mid= s+(n-s)/2;
        if(ar[mid]==k)
            return mid;
        else if(s==n){
            if(ar[s]==k)
                return s;
            else
                return -1;
        }
        else if(ar[mid]>k)
            n=mid-1;
        else if(ar[mid]<k)
            s=mid+1;
    }
    return -1;
}

bool check_sum(int *ar, int n,int sum){
    bool found=false;
    for(int i=0;i<n;i++){
        int t=sum-ar[i];
        int v=bin_search(ar,i,n,t);
        if(v!=-1){
            cout<<"Sum pair - "<<ar[i]<<" and "<<ar[v]<<endl;
            found=true;
        }
    }
    return found;
}

void display(int *ar, int n){
    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
    cout<<endl;
}

void common_in_array(int *ar1,int *ar2,int *ar3, int n1,int n2,int n3){
    int i=0,j=0,k=0,l=0;
    int col[10];
    while(i<n1 && j<n2 && k<n3){
        if(ar1[i]==ar2[j] && ar2[j]==ar2[k]){
            col[l]=ar1[i];
            i++;
            j++;
            k++;
            l++;
        }
        if(ar1[i]< ar2[j])
            i++;
        else if(ar2[j]<ar2[k])
            j++;
        else
            k++;
    }
    display(col,l);
}

int infinite_search(int *ar, int n, int k){
    int l=0,h=1;
    while(ar[h]<k && h<n){
        l=h;
        h=2*l;
        cout<<"h= "<<h<<endl;
    }
    return bin_search(ar,l,min(h,n),k);
}

int find_single(int *ar, int n){        //all element exept one is double times in array
    int x=ar[0];
    for(int i=1;i<n;i++)
        x=x^ar[i];
    return x;
}

int max_prefix_suffix_sum(int *ar,int n){
    int sum=0,pre=0,suf=0,maxsum=0;
    for(int i=0;i<n;i++)
        sum+=ar[i];
    for(int i=1;i<n;i++){
        pre+=ar[i-1];
        suf= sum-pre-ar[i];
        if(pre==suf)
            maxsum= max(pre,maxsum);
    }
    return maxsum;
}

void leader_array(int *ar, int n){
    int leader[10];
    int max_ = 0, l=0;
    for(int i=n-1;i>=0;i--){
        if(ar[i]>max_){
            leader[l]=ar[i];
            l++;
            max_=ar[i];
        }
    }
    for(int k=0;k<l;k++)
        cout<<leader[k]<<" ";
    cout<<endl;
}

int kadane_algo(int *ar, int n){
    int maxfar=ar[0];
    int maxend =0;
    for(int i=0;i<n;i++){
        maxend = maxend+ar[i];
        if(maxfar < maxend)
            maxfar =maxend;
        else if(maxend <0 )
            maxend =0;
    }
    return maxfar;
}

void find_sum_2pt(int *ar , int n, int k){
    int i=0,j=n-1;
    while(i<j){
        int s=ar[i]+ar[j];
        if(s==k){
            cout<<"Pair - "<<ar[i]<<" and "<<ar[j]<<endl;
            return;
        }
        else if(s<k)
            i++;
        else
            j--;
    }
    cout<<"pair not found";
}


int main(){
  /* int ar1[] = {1, 5, 10, 20, 40, 80};
    int ar2[] = {1,6, 7, 20, 80, 100};
    int ar3[] = {1,3, 4, 15, 20, 30, 70, 80, 120, 122,142,150,160,180,200};
    int ar4[]={1,2,5,8,5,8,2,1,6};
    int ar5[] = {-1, 2, 3, 0, 3, 2, -1};
    int ar6[]= {16, 17, 4, 3, 5, 2}; */
    int ar7[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int n=10;
    int k=7;
    /*delete_array(ar,n,k);
    insert_sorted(ar,n,-2);
    insert_sorted(ar,n,-20);
    display(ar,n);
    if(!check_sum(ar,n,10)){
        cout<<"Pair not found";
    }
    common_in_array(ar1,ar2,ar3,6,6,9);
    cout<<infinite_search(ar3,15,160);
    cout<<find_single(ar4,9);
    cout<<max_prefix_suffix_sum(ar5,7);
    leader_array(ar6,6);
    cout<<kadane_algo(ar7,8)*/
    find_sum_2pt(ar7,8,2);
    return 0;
}
