#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int mark[20];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool flag,cnt;
    int i,j,k,l,m,n,x,ans=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> m;
        while(m--)
        {
            cin >> x;
            mark[i] |= (1 << (x-1));
        }
    }
    l=(1 << n);
    for(i=0;i<l;i++)
    {
        flag=1;
        vector<int>good,bad;
        for(j=0;j<n;j++)
        {
            if((i >> j) & 1)bad.emplace_back(j);
            else good.emplace_back(j);
        }
        for(int it1 : bad)
        {
            for(int it2 : bad)
            {
                if((mark[it2] >> it1) & 1)
                {
                    flag=0;
                    break;
                }
            }
            if(!flag)break;
        }
        if(flag)
        {
            for(int it1 : good)
            {
                cnt=0;
                for(int it2 : bad)cnt |= ((mark[it1] >> it2) & 1);
                if(!cnt)
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag)++ans;
    }
    cout << ans;
    return 0;
}