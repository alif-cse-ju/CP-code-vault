#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,n,t,x,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        map<int,int>mp;
        set<int>st;
        while(n--)
        {
            cin >> x;
            ++mp[x];
            st.insert(x);
        }
        ans=0;
        for(int it : st)
        {
            if(it >= k)break;
            ans+=min(mp[it],mp[k-it]);
        }
        cout << (ans >> 1) << '\n';
    }
    return 0;
}