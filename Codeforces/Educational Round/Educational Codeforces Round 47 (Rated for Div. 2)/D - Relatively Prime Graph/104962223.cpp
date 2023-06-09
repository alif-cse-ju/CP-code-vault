#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,m,n;
    cin >> n >> m;
    if(m < n-1)
    {
        cout << "Impossible";
        return 0;
    }
    vector<pair<int,int>>v;
    for(i=1;i<n;i++)
    {
        v.emplace_back(i,i+1);
        if((int)v.size() == m)break;
    }
    if((int)v.size() < m)
    {
        for(i=3;i<=n;i++)
        {
            v.emplace_back(1,i);
            if((int)v.size() == m)break;
        }
    }
    if((int)v.size() < m)
    {
        for(i=2;i<n;i++)
        {
            for(j=i+2;j<=n;j++)
            {
                if(__gcd(i,j) > 1)continue;
                v.emplace_back(i,j);
                if((int)v.size() == m)break;
            }
            if((int)v.size() == m)break;
        }
    }
    if((int)v.size() < m)cout << "Impossible";
    else
    {
        cout << "Possible\n";
        for(pair<int,int> it : v)cout << it.first << ' ' << it.second << '\n';
    }
    return 0;
}