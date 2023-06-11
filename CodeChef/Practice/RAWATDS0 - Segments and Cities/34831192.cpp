#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    vector<PII>v;
    PII a[1000002];
    int i,n,x,y,ans=0,cur;
    cin >> n >> cur;
    for(i=0;i<n;i++)
    {
        cin >> x >> y;
        a[i].first=min(x,y);
        a[i].second=max(x,y);
    }
    sort(a,a+n);
    x=a[0].first,y=a[0].second;
    for(i=1;i<n;i++)
    {
        if(a[i].first <= y)y=max(y,a[i].second);
        else
        {
            v.emplace_back(x,y);
            x=a[i].first,y=a[i].second;
        }
    }
    v.emplace_back(x,y);
    for(PII it : v)
    {
        if(it.first <= cur  &&  it.second >= cur)
        {
            ans=it.second-it.first+1;
            break;
        }
    }
    cout << ans;
    return 0;
}