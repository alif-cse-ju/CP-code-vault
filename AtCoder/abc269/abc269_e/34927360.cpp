#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=5e5+5;
const int N=2e6+5;
const int mod=998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    int l=1, r=n;
    while(l <= r)
    {
        int m=(l+r) >> 1;
        cout << "? 1 " << m << " 1 " << n << endl;
        int v;cin >> v;
        if(v == m)l=m+1;
        else r=m-1;
    }
    int row=r+1;
    l=1, r=n;
    while(l <= r)
    {
        int m=(l+r) >> 1;
        cout << "? 1 " << n << " 1 " << m << endl;
        int v;cin >> v;
        if(v == m)l=m+1;
        else r=m-1;
    }
    int col=r+1;
    cout << "! " << row << ' ' << col << endl;
    return 0;
}
