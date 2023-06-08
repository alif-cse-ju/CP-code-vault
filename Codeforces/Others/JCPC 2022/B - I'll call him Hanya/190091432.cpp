#include<bits/stdc++.h>
using namespace std;
int main()
    freopen("hanya.in","r",stdin);
    int tc;
    cin>>tc;
    while(tc--){
        long long n,m=0,i,j=0,k;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>k;
            if(k<0)j=1;
            else if(k>0)m=1;
        }
        cout<<max(0ll,j+m)<<"\n";
    }