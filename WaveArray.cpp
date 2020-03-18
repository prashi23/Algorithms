vector<int> Solution::wave(vector<int> &A) {
    
    int n = A.size();
    sort(A.begin(),A.end());
    vector<int> v;
    for(int i=0;i<n;i++)
        v.push_back(0);
        
    int j=0,k=1;
    for(int i=0;i<n;i++)
    {
        
        if(i%2)
        {
            v[j]=A[i];
            j=j+2;
        }
        else
        {
            v[k] = A[i];
            k=k+2;
        }
    }
    
    if(n%2)
        v[n-1] = A[n-1];
        
    return v;
}
