#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N+5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,m,n;
    long long ans=0;
    map<long long,bool>mp;
    cin >> n >> m;
    for(i=1;i<=n;i++)a[i]=i,ans+=i,mp[i]=1;
    while(m--)
    {
        cin >> k;
        if(mp.find(k) == mp.end())
        {
            mp.erase(a[n]);
            mp[k]=1;
            ans+=k-a[n];
            a[n]=k;
        }
        else swap(a[1],a[n]);
        cout << ans << '\n';
    }
    return 0;
}