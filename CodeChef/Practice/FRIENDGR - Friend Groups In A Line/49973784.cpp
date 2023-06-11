#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
char s[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,l,t,ans,last;
    cin >> t;
    while(t--)
    {
        cin >> l >> k >> s+1;
        last=-1e7;
        vector<int>v;
        for(i=1;i<=l;i++)
        {
            if(s[i] == '1')
            {
                if(i-k-1 == last)
                {
                    last=i-1;
                    v.emplace_back(i-1);
                }
                else if(i-k == last)
                {
                    last=i;
                    v.emplace_back(i);
                }
                else
                {
                    last=i+1;
                    v.emplace_back(i+1);
                }
            }
        }
        ans=0,last=-1e7;
        for(int it : v)
        {
            if(it-last > k)++ans;
            last=it;
        }
        cout << ans << '\n';
    }
    return 0;
}