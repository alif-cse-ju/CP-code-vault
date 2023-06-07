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
const int mod=998244353;

int n;
char s[M];
ll dpTree[4*M];
string sTree[4*M];

void Build(int nodeNum)
{
    if(nodeNum+nodeNum >= n)
    {
        dpTree[nodeNum]=1;
        sTree[nodeNum] += s[nodeNum];
        return;
    }

    Build(2*nodeNum), Build(2*nodeNum+1);
    dpTree[nodeNum]=(dpTree[2*nodeNum] * dpTree[2*nodeNum+1]) % mod;

    if(sTree[2*nodeNum] != sTree[2*nodeNum+1])
    {
        dpTree[nodeNum] += dpTree[nodeNum];
        if(dpTree[nodeNum] >= mod)dpTree[nodeNum] -= mod;

        if(sTree[2*nodeNum] < sTree[2*nodeNum+1])sTree[nodeNum]=s[nodeNum] + sTree[2*nodeNum] + sTree[2*nodeNum+1];
        else sTree[nodeNum]=s[nodeNum] + sTree[2*nodeNum+1] + sTree[2*nodeNum];
    }
    else sTree[nodeNum]=s[nodeNum] + sTree[2*nodeNum] + sTree[2*nodeNum+1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s+1;
    n=(1 << n)-1;
    Build(1);
    cout << dpTree[1];
    return 0;
}