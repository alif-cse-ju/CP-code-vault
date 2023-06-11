#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e3+5;
const int mod=998244353;
bool mark[N];
int parent[N];
int FindParent(int x)
{
    if(parent[x] == x)return x;
    return parent[x]=FindParent(parent[x]);
}
long long BigMod(long long val,long long pow)
{
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}
int main()
{
    FAST();
    int c,i,j,k,l,m,n,px,py,r,t,x,y,clubCnt;
    cin >> t;
    while(t--)
    {
        cin >> c >> n >> m;
        for(i=1;i<=c;i++)
        {
            mark[i]=0;
            parent[i]=i;
        }
        vector<pair<pair<int,int>,int>>v;
        for(i=1;i<=c;i++)
        {
            cin >> k;
            while(k--)
            {
                cin >> l >> r;
                v.push_back({{l,r},i});
            }
        }
        sort(v.begin(),v.end());
        vector<int>temp;
        for(i=0;i<(int)v.size();)
        {
            temp.clear();
            for(j=i;j<(int)v.size();j++)
            {
                if(v[j].first.first > v[i].first.second)break;
                temp.emplace_back(v[j].second);
                v[i].first.second=max(v[i].first.second,v[j].first.second);
            }
            n-=(v[i].first.second-v[i].first.first+1);
            i=j;
            x=temp[0];
            px=FindParent(x);
            for(j=1;j<(int)temp.size();j++)
            {
                y=temp[j];
                py=FindParent(y);
                if(px != py)parent[py]=px;
            }
        }
        clubCnt=n;
        for(i=1;i<=c;i++)
        {
            px=FindParent(i);
            if(!mark[px])
            {
                ++clubCnt;
                mark[px]=1;
            }
        }
        cout << BigMod(m,clubCnt) << '\n';
    }
    return 0;
}