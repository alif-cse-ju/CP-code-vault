#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N+2],b[N+2];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,n,t,mn;
    cin >> t;
    while(t--)
    {
        cin >> n;
        mn=INT_MAX;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            b[i]=a[i],mn=min(mn,a[i]);
        }
        vector<int>v;
        sort(b+1,b+n+1);
        for(i=1;i<=n;i++)
        {
            if(a[i] != b[i])v.emplace_back(b[i]);
        }
        l=(int)v.size();
        for(i=0;i<l;i++)
        {
            if(v[i]%mn != 0)break;
        }
        if(i == l)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;