#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
bool mark[M];
void Sieve()
    ll i,j;
    for(i=4;i<M;i+=2)mark[i]=1;
    for(i=3;i<M;i+=2)
    {
        if(!mark[i])
        {
            for(j=i*i;j<M;j+=2*i)mark[j]=1;
        }
    }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,sum,t,x;
    Sieve();
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>odd,even;
        sum=0;
        for(i=1;i<=n;i++)
        {
            cin >> x, sum += x;
            if(x & 1)odd.emplace_back(i);
            else even.emplace_back(i);
        }
        if(mark[sum])
        {
            cout << n << '\n';
            for(i=1;i<=n;i++)cout << i << ' ';
            cout << '\n';
        }
        else
        {
            odd.pop_back();
            cout << n-1 << '\n';
            for(int it : odd)cout << it << ' ';
            for(int it : even)cout << it << ' ';
            cout << '\n';
        }
    }
    return 0;
}