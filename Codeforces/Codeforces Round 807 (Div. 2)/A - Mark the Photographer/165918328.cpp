#include <bits/stdc++.h>
using namespace std;

string Solve()
{
    int k,n;cin >> n>> k;
    vector<int>v(2*n);
    for(int &x : v)cin >> x;
    sort(v.begin(),v.end());
    for(int i=n;i<n+n;i++)
    {
        if(v[i]-v[i-n] < k)return "NO";
    }
    return "YES";
}

int32_t main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;cin >> t;
    while(t--)cout << Solve() << '\n';
    return 0;
}