#include<bits/stdc++.h>
 using namespace std;
 const int N=1e6+5;
const int mod=1e9+7;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,k,n,t,x;
    long long ans=0;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        vector<int>v[k];
        for(i=0,j=0;i<k*n;i++)
        {
            cin >> x;
            v[j].emplace_back(x);
            if((int)v[j].size() < (n+1)/2)j=(j+1)%k;
            else if((int)v[j].size() == n)j=(j+1)%k;
        }
        ans=0;
        for(i=0;i<k;i++)ans+=v[i][(n+1)/2-1];
        cout << ans << '\n';
    }
    return 0;
}