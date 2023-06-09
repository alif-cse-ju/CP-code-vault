#include<bits/stdc++.h>
using namespace std;
int cnt[200002];
#define PII pair<int,int>
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i,n,mx=-1,pos=1;
    cin >> n;
    int a[n+1];
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        ++cnt[a[i]];
        if(mx < cnt[a[i]])
        {
            pos=i;
            mx=cnt[a[i]];
        }
    }
    vector<pair<int,PII> >ans;
    for(i=pos-1;i>0;i--)
    {
        if(a[i] < a[pos])ans.push_back({1,{i,i+1}});
        else if(a[i] > a[pos])ans.push_back({2,{i,i+1}});
        a[i]=a[pos];
    }
    for(i=pos+1;i<=n;i++)
    {
        if(a[i] < a[pos])ans.push_back({1,{i,i-1}});
        else if(a[i] > a[pos])ans.push_back({2,{i,i-1}});
        a[i]=a[pos];
    }
    cout << ans.size() << '\n';
    for(auto x : ans)cout << x.first << ' ' << x.second.first << ' ' << x.second.second << '\n';
    return 0;
}