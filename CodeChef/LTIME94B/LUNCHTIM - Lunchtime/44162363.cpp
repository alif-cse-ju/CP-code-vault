#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e5+5;
const int mod=1e9+7;
vector<int>v[N];
int a[N],node[4*N],fnAns[N];
void Build(int nodeNum,int l,int r)
{
    if(l == r)
    {
        node[nodeNum]=a[l];
        return;
    }
    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    node[nodeNum]=max(node[2*nodeNum],node[2*nodeNum+1]);
}
int Query(int nodeNum,int start,int end,int l,int r)
{
    if(l == start  &&  r == end)return node[nodeNum];
    int mid=(start+end) >> 1;
    if(r <= mid)return Query(nodeNum*2,start,mid,l,r);
    if(mid < l)return Query(nodeNum*2+1,mid+1,end,l,r);
    return max(Query(nodeNum*2,start,mid,l,mid),Query(nodeNum*2+1,mid+1,end,mid+1,r));
}
int main()
{
    FAST();
    int i,j,l,m,n,r,t,ans,cnt,temp;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt=0;
        map<int,int>mp;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            if(mp.find(a[i]) == mp.end())mp[a[i]]=++cnt;
            v[mp[a[i]]].emplace_back(i);
        }
        Build(1,1,n);
        for(i=1;i<=cnt;i++)
        {
            for(j=0;j<(int)v[i].size();j++)
            {
                ans=0;
                l=0,r=j,temp=0;
                while(l <= r)
                {
                    m=(l+r) >> 1;
                    if(Query(1,1,n,v[i][m],v[i][j]) == a[v[i][j]])temp=m,r=m-1;
                    else l=m+1;
                }
                ans+=j-temp;
                l=j,r=(int)v[i].size()-1,temp=0;
                while(l <= r)
                {
                    m=(l+r) >> 1;
                    if(Query(1,1,n,v[i][j],v[i][m]) == a[v[i][j]])temp=m,l=m+1;
                    else r=m-1;
                }
                ans+=temp-j;
                fnAns[v[i][j]]=ans;
            }
            v[i].clear();
        }
        for(i=1;i<=n;i++)cout << fnAns[i] << ' ';
        cout << '\n';
    }
    return 0;
}