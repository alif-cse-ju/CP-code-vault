#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    map<long long,int>mp;
    mp[0]=1;
    int i,l=0,n,x;
    long long sum=0,ans=0;
    cin >> n;
    for(i=2;i<=n+1;i++)
    {
        cin >> x;
        sum+=x;
        if(mp.find(sum) != mp.end())
        {
            if(mp[sum] >= l)
            {
                ++ans;
                l=i-1;
            }
        }
        mp[sum]=i;
    }
    cout << ans;
    return 0;