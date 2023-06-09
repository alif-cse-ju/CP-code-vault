#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct Data
    int i,j,k;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,x,xr=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> x;
        xr ^= x;
    }
    vector<Data>ans;
    if(n & 1)
    {
        for(i=1;i+2<=n;i+=2)ans.push_back({i,i+1,i+2});
        for(i=n-4;i>=1;i-=2)ans.push_back({i,i+1,i+2});
    }
    else
    {
        if(xr)
        {
            cout << "NO";
            return 0;
        }
        n--;
        for(i=1;i+2<=n;i+=2)ans.push_back({i,i+1,i+2});
        for(i=n-4;i>=1;i-=2)ans.push_back({i,i+1,i+2});
    }
    cout << "YES\n" << (int)ans.size() << '\n';
    for(Data it : ans)cout << it.i << ' ' << it.j << ' ' << it.k << '\n';
    return 0;
}