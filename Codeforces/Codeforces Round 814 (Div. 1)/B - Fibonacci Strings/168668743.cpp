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
const int M=2e5+5;
const int N=5e6+5;
const int mod=998244353;
ll a[102],fib[60],fibSum[60];
void PreCal()
    fibSum[1]=2;
    fib[0]=fib[1]=fibSum[0]=1;
    for(int i=2;i<60;i++)fib[i]=fib[i-1]+fib[i-2], fibSum[i]=fib[i]+fibSum[i-1];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        ll sum=0;
        for(int i=1;i<=n;i++)cin >> a[i], sum+=a[i];
        int m;
        bool ok=0;
        for(int i=0;i<60;i++)
        {
            if(fibSum[i] >= sum)
            {
                ok = (fibSum[i] == sum), m=i;
                break;
            }
        }
        if(!ok)cout << "NO\n";
        else
        {
            ok=1;
            int last=0;
            for(int i=m;i>=0  &&  ok;i--)
            {
                int cur=0;
                for(int j=1;j<=n;j++)
                {
                    if(j == last)continue;
                    if(a[j] > a[cur])cur=j;
                }
                if(a[cur] < fib[i])ok=0;
                else last=cur, a[last]-=fib[i];
            }
            if(ok)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}