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
const int mod=1e9+7;
bool mark[M];
vector<int>prime;
int in[M],mx[M][2];
void Sieve()
    ll i,j;
    mx[2][0]=mx[2][1]=50;
    prime.emplace_back(2);
    for(i=3;i<M;i+=2)
    {
        if(!mark[i])
        {
            mx[i][0]=mx[i][1]=50;
            prime.emplace_back(i);
            for(j=i*i;j<M;j+=2*i)mark[j]=1;
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=1;
    int cnt,i,n,x,y;
    Sieve();
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> x;
        for(int p : prime)
        {
            if(1ll*p*p > x)break;
            cnt=0;
            while(x%p == 0)++cnt, x/=p;
            if(!cnt)continue;
            ++in[p];
            if(cnt <= mx[p][0])mx[p][1]=mx[p][0], mx[p][0]=cnt;
            else if(cnt < mx[p][1])mx[p][1]=cnt;
        }
        if(x > 1)
        {
            ++in[x];
            if(mx[x][0] >= 1)mx[x][1]=mx[x][0], mx[x][0]=1;
            else if(mx[x][1] > 1)mx[x][1]=1;
        }
    }
    for(int p : prime)
    {
        if(in[p] < n-1)continue;
        if(in[p] == n-1)mx[p][1]=mx[p][0];
        while(mx[p][1]--)ans *= p;
    }
    cout << ans;
    return 0;
}