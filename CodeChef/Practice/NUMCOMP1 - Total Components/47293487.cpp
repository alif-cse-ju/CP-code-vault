#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e7+5;
const int N=2e5+5;
const int mod=1e9+7;
ordered_set<int>prime;
void Sieve()
{
    bitset<M>sieve;
    int finalBit = sqrt(M) + 1;
    prime.insert(2);
    for(int i = 3,j; i < M; i+=2)
    {
        if(!sieve.test(i))
        {
            prime.insert(i);
            if(i < finalBit)
            {
                for(j = i*i; j < M; j+=2*i)sieve.set(j);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t;
    Sieve();
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << prime.order_of_key(n+1)-prime.order_of_key(n/2+1)+(n/2 >= 2) << '\n';
    }
    return 0;
}