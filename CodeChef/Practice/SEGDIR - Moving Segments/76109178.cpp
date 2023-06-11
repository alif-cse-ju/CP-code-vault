#include<bits/stdc++.h>
using namespace std;
void Solve()
{
    int n;cin >> n;
    map<int,vector<pair<int,int>>>mp;
    while(n--)
    {
        int l,r,v;cin >> l >> r >> v;
        mp[v].emplace_back(l,r);
    }
    for(auto [x,v] : mp)
    {
        int R0=0, R1=0;
        sort(v.begin(),v.end());
        for(auto [l,r] : v)
        {
            if(l > R0)R0=r;
            else if(l > R1)R1=r;
            else
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin >> t;
    while(t--)Solve();
    return 0;
}