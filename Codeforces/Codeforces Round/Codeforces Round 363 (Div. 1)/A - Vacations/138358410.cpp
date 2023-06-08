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
const int M=1e2+5;
const int N=2e6+5;
const int mod=1e9+7;
int a[M],dp[M][3],n;
int Nirjhor_28_69(int i,int last)
    if(i > n)return 0;
    int &ans=dp[i][last];
    if(ans != -1)return ans;
    ans=1+Nirjhor_28_69(i+1,0);
    if(!last)
    {
        if(a[i] == 1)ans=min(ans, Nirjhor_28_69(i+1,1));
        else if(a[i] == 2)ans=min(ans, Nirjhor_28_69(i+1,2));
        else if(a[i] == 3)ans=min(ans, min(Nirjhor_28_69(i+1,1), Nirjhor_28_69(i+1,2)));
    }
    else if(last == 1)
    {
        if(a[i] == 2  ||  a[i] == 3)ans=min(ans, Nirjhor_28_69(i+1,2));
    }
    else
    {
        if(a[i] == 1  ||  a[i] == 3)ans=min(ans, Nirjhor_28_69(i+1,1));
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    memset(dp,-1,sizeof(dp));
    cout << Nirjhor_28_69(1,0);
    return 0;
}