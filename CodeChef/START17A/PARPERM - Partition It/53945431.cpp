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
const int N=1e6+5;
const int mod=1e9+7;
bool mark[M];
int id,primes[M];
ordered_set<int>ost;
void Sieve()
{
    int i,j;
    primes[id=1]=2;
    ost.insert(2);
    for(i=3;i<M;i+=2)
    {
        if(!mark[i])
        {
            primes[++id]=i, ost.insert(i);
            if(i > sqrt(M))continue;
            for(j=i*i;j<M;j+=2*i)mark[j]=1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,kk,l,n,r,t;
    cin >> t;
    Sieve();
    while(t--)
    {
        cin >> n >> k;
        if(k <= n-k)
        {
            l=ost.order_of_key(n/2+1);
            r=ost.order_of_key(n+1);
            if(r-l+1 < k)cout << "NO\n";
            else
            {
                vector<int>ans;
                ans.emplace_back(1), --k;
                for(i=l+1;i<=r  &&  k;i++,k--)ans.emplace_back(primes[i]);
                cout << "YES\n";
                for(int it : ans)cout << it << ' ';
                cout << '\n';
            }
        }
        else
        {
            kk=n-k;
            l=ost.order_of_key(n/2+1);
            r=ost.order_of_key(n+1);
            if(r-l+1 < kk)cout << "NO\n";
            else
            {
                for(i=1;i<=n;i++)mark[i]=0;
                mark[1]=1, --kk;
                for(i=l+1;i<=r  &&  kk;i++,kk--)mark[primes[i]]=1;
                cout << "YES\n";
                for(i=1;i<=n;i++)
                {
                    if(!mark[i])cout << i << ' ';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}