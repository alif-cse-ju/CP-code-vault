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
bool mark[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        deque<int>per,rem;
        for(i=1;i<=n;i++)mark[i]=0;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            if(x > n)rem.emplace_back(x);
            else
            {
                if(!mark[x])mark[x]=1;
                else rem.emplace_back(x);
            }
        }
        for(i=1;i<=n;i++)
        {
            if(!mark[i])per.emplace_back(i);
        }
        sort(per.begin(),per.end());
        sort(rem.begin(),rem.end());
        ans=(int)per.size();
        while(!per.empty())
        {
            x=per.front(), per.pop_front();
            y=rem.front(), rem.pop_front();
            if(x > (y-1)/2)
            {
                ans=-1;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}