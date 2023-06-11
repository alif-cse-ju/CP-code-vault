#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
char s[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string X;
    int i,l,y;
    long long ans=0;
    cin >> s+1 >> X >> y;
    l=strlen(s+1);
    vector<long long>v;
    v.emplace_back(0);
    for(i=1;i<=l;i++)
    {
        if(s[i] == X[0])v.emplace_back(i);
    }
    v.emplace_back(l+1);
    l=((int)v.size())-1;
    for(i=1;i+y-1<l;i++)ans+=(v[i]-v[i-1])*(v[i+y]-v[i+y-1]);
    cout << ans;
    return 0;
}