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
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
bool isPrime(const ll& n)
    if(n > 2  &&  n%2 == 0)return 0;
    for(ll i=3;i*i<=n;i+=2)
    {
        if(n > i  &&  n%i == 0)return 0;
    }
    return 1;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt,t;
    ll d,i,rt,x;
    cin >> t;
    while(t--)
    {
        cin >> x >> d;
        cnt=0;
        while(x%d == 0)++cnt, x/=d;
        if(cnt == 1)cout << "NO\n";
        else
        {
            if(!isPrime(x))cout << "YES\n";
            else
            {
                if(cnt == 2)cout << "NO\n";
                else
                {
                    if(isPrime(d))cout << "NO\n";
                    else
                    {
                        rt=sqrt(d);
                        if(rt*rt == d  &&  x == rt  &&  cnt == 3)cout << "NO\n";
                        else cout << "YES\n";
                    }
                }
            }
        }
    }
    return 0;
}