#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[M],ans[M];
priority_queue<pair<pair<int,int>,int>>pq;
void Dijkstra()
{
    int idx,val;
    while(!pq.empty())
    {
        idx=pq.top().second;
        val=pq.top().first.first+1;
        pq.pop();
        if(a[idx+1] > a[idx]  &&  ans[idx+1] < val)
        {
            ans[idx+1]=val;
            pq.push({{val,-a[idx+1]},idx+1});
        }
        if(a[idx-1] > a[idx]  &&  ans[idx-1] < val)
        {
            ans[idx-1]=val;
            pq.push({{val,-a[idx-1]},idx-1});
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    long long sum=0;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        ans[i]=1;
        cin >> a[i];
        pq.push({{1,-a[i]},i});
    }
    Dijkstra();
    for(i=1;i<=n;i++)sum+=ans[i];
    cout << sum;
    return 0;
}