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
char s[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,j,k,l,t,x;
    cin >> t;
    while(t--)
    {
        ans=0;
        vector<int>v;
        cin >> l >> k >> s+1;
        for(i=1;i<=k;i++)
        {
            for(j=i;j<=l;j+=k)
            {
                if(s[j] == '1')v.emplace_back(j);
            }
            while(!v.empty())
            {
                x=v.back();
                v.pop_back();
                if(x-k < 1)
                {
                    if(x+k > l)++ans,s[x]='0';
                    else
                    {
                        if(s[x+k] == '1')continue;
                        ++ans,s[x+k]='1';
                    }
                }
                else
                {
                    if(x+k <= l  &&  s[x+k] == '1')continue;
                    if(s[x-k] == '1')continue;
                    ++ans,s[x-k]='1';
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}