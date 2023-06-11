#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll val;
    string x,y;
    map<ll,bool>cnt;
    int i,j,lx,ly,n;
    cin >> x >> y;
    lx=(int)x.size();
    ly=(int)y.size();
    n=1 << lx;
    for(i=1;i<n;i++)
    {
        val=0;
        for(j=0;j<lx;j++)
        {
            if((i >> j) & 1)val=val*10+(x[j]-'0');
        }
        cnt[val]=1;
    }
    set<pair<ll,ll>>st;
    n=1 << ly;
    for(i=1;i<n;i++)
    {
        val=0;
        for(j=0;j<ly;j++)
        {
            if((i >> j) & 1)val=val*10+(y[j]-'0');
        }
        if(cnt.find(val) != cnt.end())st.emplace(val,val);
    }
    cout << (int)st.size();
    return 0;
}