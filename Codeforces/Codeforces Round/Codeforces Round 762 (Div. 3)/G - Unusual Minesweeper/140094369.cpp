#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
ll X[M],Y[M];
vector<pair<int,int>>col[M], row[M];
int par[M],_timer[M],connectedTimer[M];
int FindParent(int n)
    if(par[n] == n)return n;
    return par[n]=FindParent(par[n]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k,x,y;
    int ans,cntC,cntR,i,n,px,py,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        set<int>stCol,stRow;
        map<int,int>mpCol,mpRow;
        for(i=1;i<=n;i++)
        {
            col[i].clear(), row[i].clear();
            par[i]=i, connectedTimer[i]=INT_MAX;
            cin >> X[i] >> Y[i] >> _timer[i];
            stRow.insert(X[i]), stCol.insert(Y[i]);
        }
        cntR=0;
        for(ll it : stRow)mpRow[it]=++cntR;
        cntC=0;
        for(ll it : stCol)mpCol[it]=++cntC;
        for(i=1;i<=n;i++)
        {
            row[mpRow[X[i]]].emplace_back(Y[i],i);
            col[mpCol[Y[i]]].emplace_back(X[i],i);
        }
        for(i=1;i<=cntC;i++)
        {
            sort(col[i].begin(),col[i].end());
            reverse(col[i].begin(),col[i].end());
            while(!col[i].empty())
            {
                x=col[i].back().first, px=FindParent(col[i].back().second), col[i].pop_back();
                while(!col[i].empty()  &&  col[i].back().first <= x+k)
                {
                    y=col[i].back().first, py=FindParent(col[i].back().second), col[i].pop_back();
                    if(px != py)par[py]=px;
                    x=y;
                }
            }
        }
        for(i=1;i<=cntR;i++)
        {
            sort(row[i].begin(),row[i].end());
            reverse(row[i].begin(),row[i].end());
            while(!row[i].empty())
            {
                x=row[i].back().first, px=FindParent(row[i].back().second), row[i].pop_back();
                while(!row[i].empty()  &&  row[i].back().first <= x+k)
                {
                    y=row[i].back().first, py=FindParent(row[i].back().second), row[i].pop_back();
                    if(px != py)par[py]=px;
                    x=y;
                }
            }
        }
        for(i=1;i<=n;i++)px=FindParent(i), connectedTimer[px]=min(connectedTimer[px], _timer[i]);
        deque<int>dq;
        for(i=1;i<=n;i++)
        {
            if(connectedTimer[i] < INT_MAX)dq.emplace_back(connectedTimer[i]);
        }
        sort(dq.begin(),dq.end());
        ans=-1;
        while(!dq.empty())
        {
            ++ans;
            while(!dq.empty()  &&  dq.front() == ans)dq.pop_front();
            if(!dq.empty())dq.pop_back();
        }
        cout << ans << '\n';
    }
    return 0;
}