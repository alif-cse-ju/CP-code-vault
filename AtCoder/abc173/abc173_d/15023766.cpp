#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    LL ans;
    int i,n,x,y,a[200002];
    priority_queue<pair<int,int>>pq;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    ans=a[n],i=n-2;
    pq.emplace(a[n-1],a[n]);
    pq.emplace(a[n-1],a[n]);
    while(i > 0)
    {
        x=pq.top().first;
        y=pq.top().second;
        pq.pop();
        ans+=x;
        pq.emplace(a[i],x);
        pq.emplace(a[i--],y);
    }
    cout << ans;
    return 0;
}
