#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
char s[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s+1;
    ll ans=0;
    int A=0, B=0, C=0, l=strlen(s+1);
    map<tuple<int,int,int>,int>mp;
    mp[make_tuple(0,0,0)]=1;
    for(int i=1;i<=l;i++)
    {
        if(s[i] == 'A')++A;
        else if(s[i] == 'B')++B;
        else ++C;
        ans += mp[make_tuple(0,B-A,C-A)], ++mp[make_tuple(0,B-A,C-A)];
    }
    cout << ans;
    return 0;
}