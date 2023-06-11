#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,n,x,y;
    priority_queue<pair<PII,int> >pq;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x >> y;
        pq.push({{-y,x},i});
    }
    while(!pq.empty())
    {
        cout << pq.top().second << ' ';
        pq.pop();
    }
    return 0;
}