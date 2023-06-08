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
const int N=2e6+5;
const int mod=1e9+7;
int cnt[32];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int gcd,i,j,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0;i<30;i++)cnt[i]=0;
        for(i=0;i<n;i++)
        {
            cin >> x;
            for(j=0;j<30;j++)
            {
                if((x >> j) & 1)++cnt[j];
            }
        }
        gcd=cnt[0];
        for(i=1;i<30;i++)gcd=__gcd(gcd,cnt[i]);
        if(!gcd)
        {
            for(i=1;i<=n;i++)cout << i << ' ';
        }
        else
        {
            vector<int>ans;
            for(i=1;i*i<=gcd;i++)
            {
                if(gcd%i == 0)
                {
                    ans.emplace_back(i);
                    if(i != gcd/i)ans.emplace_back(gcd/i);
                }
            }
            sort(ans.begin(),ans.end());
            for(int it : ans)cout << it << ' ';
        }
        cout << '\n';
    }
    return 0;
}