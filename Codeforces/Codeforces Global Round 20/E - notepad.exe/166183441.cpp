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

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int Ask(int x)
{
    cout << "? " << x << endl;
    int y;cin >> y;
    return y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    int l=1, r=(N+N+N);
    while(l <= r)
    {
        int m=(l+r) >> 1;
        int v=Ask(m);
        if(v == 1)r=m-1;
        else l=m+1;
    }
    int ans=INT_MAX, mxArea=r+1;
    for(int i=1;i<=n;i++)
    {
        int q=Ask(mxArea/i);
        if(q)ans=min(ans, q * (mxArea/i));
    }
    cout << "! " << ans << endl;
    return 0;
}