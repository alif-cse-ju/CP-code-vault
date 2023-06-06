#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;

int ans[M],parRail[M],parRoad[M];

int FindParRail(int n)
{
    if(parRail[n] == n)return n;
    return parRail[n]=FindParRail(parRail[n]);
}

int FindParRoad(int n)
{
    if(parRoad[n] == n)return n;
    return parRoad[n]=FindParRoad(parRoad[n]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,l,n,px,py,x,y;
    cin >> n >> k >> l;
    for(i=1;i<=n;i++)parRail[i]=parRoad[i]=i;
    while(k--)
    {
        cin >> x >> y;
        px=FindParRoad(x);
        py=FindParRoad(y);
        if(px != py)parRoad[px]=py;
    }
    while(l--)
    {
        cin >> x >> y;
        px=FindParRail(x);
        py=FindParRail(y);
        if(px != py)parRail[px]=py;
    }
    map<pair<int,int>,int>cnt;
    for(i=1;i<=n;i++)x=FindParRail(i), y=FindParRoad(i), ++cnt[{x,y}];
    for(i=1;i<=n;i++)x=FindParRail(i), y=FindParRoad(i), cout << cnt[{x,y}] << ' ';
    return 0;
}