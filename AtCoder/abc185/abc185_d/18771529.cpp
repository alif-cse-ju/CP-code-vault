#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
const int mod=1e9+7;

int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,m,n,ans=0,mn=INT_MAX;
    cin >> n >> m;
    for(i=1;i<=m;i++)cin >> a[i];
    if(m == 0)
    {
        cout << '1';
        return 0;
    }
    sort(a+1,a+m+1);
    vector<int>v;
    if(a[1] > 1)v.emplace_back(a[1]-1);
    if(a[m] < n)v.emplace_back(n-a[m]);
    for(i=2;i<=m;i++)v.emplace_back(a[i]-a[i-1]-1);
    for(int it : v)
    {
        if(!it)continue;
        mn=min(mn,it);
    }
    for(int it : v)ans+=(it+mn-1)/mn;
    cout << ans;
    return 0;
}