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
int a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m=0,n,x;
    long long ans=LLONG_MAX,temp;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        if(x == 1)a[++m]=i;
    }
    if(m == 1)cout << "-1";
    else
    {
        vector<int>divs;
        for(i=2;i<=m;i++)
        {
            if(m%i == 0)divs.emplace_back(i);
        }
        for(int it : divs)
        {
            temp=0;
            for(i=it;i<=m;i+=it)
            {
                for(j=i-it+1;j<=i;j++)temp+=abs(a[j]-a[i-it/2]);
            }
            ans=min(ans,temp);
        }
        cout << ans;
    }
    return 0;
}