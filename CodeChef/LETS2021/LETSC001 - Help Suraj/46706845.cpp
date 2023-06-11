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
const int M=1e6+5;
const int N=2e5+5;
const int mod=1e9+7;
int cnt[M];
bool mark[M];
void Sieve()
{
    int i,j;
    cnt[2]=1;
    for(i=3;i<M;i+=2)
    {
        if(!mark[i])
        {
            cnt[i]=1;
            if(i <= 1e3)
            {
                for(j=i*i;j<M;j+=(i << 1))mark[j]=1;
            }
        }
    }
    for(i=2;i<M;i++)cnt[i]+=cnt[i-1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    Sieve();
    cin >> n;
    cout << cnt[n];
    return 0;
}