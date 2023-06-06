#include<bits/stdc++.h>

using namespace std;

const int N=1e4+5;
const int mod=1e9+7;

int n,a[N];
pair<long long,int>node[4*N];

void Build(int nodeNum,int l,int r)
{
    if(l == r)
    {
        node[nodeNum].first=a[l];
        node[nodeNum].second=l;
        return;
    }

    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    node[nodeNum]=min(node[2*nodeNum],node[2*nodeNum+1]);
}

pair<long long,int> Query(int nodeNum,int start,int end,int l,int r)
{
    if(l == start  &&  r == end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    if(mid < l)return Query(nodeNum*2+1,mid+1,end,l,r);
    return min(Query(nodeNum*2,start,mid,l,mid),Query(nodeNum*2+1,mid+1,end,mid+1,r));
}

long long Check(int l,int r)
{
    if(l > r)return 0;
    pair<long long,int>temp=Query(1,1,n,l,r);
    long long ans=(r-l+1)*temp.first;
    ans=max(ans,Check(l,temp.second-1));
    ans=max(ans,Check(temp.second+1,r));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    Build(1,1,n);
    cout << Check(1,n);
    return 0;
}