#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int s,b,i,x;
    cin >> s >> b;
    int a[s];
    pair<int,int>dg[b];
    for(i=0;i<s;i++)cin >> a[i];
    for(i=0;i<b;i++)cin >> dg[i].first >> dg[i].second;
    sort(dg,dg+b);
    long long int ans[b];
    ans[0]=dg[0].second;
    for(i=1;i<b;i++)ans[i]=ans[i-1]+dg[i].second;
    for(i=0;i<s;i++)
    {
        if(a[i] < dg[0].first)cout << "0 ";
        else if(a[i] >= dg[b-1].first)cout << ans[b-1] << ' ';
        else
        {
            x=upper_bound(dg,dg+b,make_pair(a[i],INT_MAX))-dg;
            cout << ans[x-1] << ' ';
        }
    }
    return 0;