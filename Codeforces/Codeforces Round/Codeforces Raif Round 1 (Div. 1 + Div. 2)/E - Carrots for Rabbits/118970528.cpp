#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
long long Calc(long long l,long long n)
    long long len=l/n;
    long long rem=l%n;
    return (n-rem)*len*len+rem*(len+1)*(len+1);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,n;
    long long ans=0,x;
    priority_queue<tuple<long long,long long,long long>>pq;
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> x;
        ans+=x*x;
        pq.emplace(make_tuple(Calc(x,1)-Calc(x,2),x,2));
    }
    k-=n;
    while(k--)
    {
        auto [cur,len,i]=pq.top();
        pq.pop();
        ans-=cur;
        pq.emplace(make_tuple(Calc(len,i)-Calc(len,i+1),len,i+1));
    }
    cout << ans;
    return 0;
}