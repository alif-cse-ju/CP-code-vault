#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
const int PW = (1 << 18);
int dpPW[PW+5],sum[M];
void PreProcess()
    for(int i=PW;i;i--)
    {
        if(__builtin_popcount(i) == 1)dpPW[i]=0;
        else dpPW[i]=dpPW[i+1]+1;
    }
int Check(const int& n)
    int i,j,k,ans=INT_MAX,x,y;
    ordered_set<int>ost;
    for(i=1;i<=n;i++)
    {
        if(sum[i])ost.insert(sum[i]);
    }
    for(i=1;i<=n;i++)
    {
        if(!sum[i]  ||  sum[i] == sum[i-1])continue;
        for(j=0;j<19;j++)
        {
            x=(1 << j)+sum[i];
            k=ost.order_of_key(x+1);
            if(k == (int)ost.size())break;
            y=*(ost.find_by_order(k-1));
            if(y == sum[i])continue;
            ans=min(ans, dpPW[sum[i]]+x-y+dpPW[sum[n]-y]);
        }
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,n,t,x;
    PreProcess();
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)sum[i]=0;
        for(i=1;i<=n;i++)cin >> x, ++sum[x];
        for(i=2;i<=n;i++)sum[i] += sum[i-1];
         ans=dpPW[sum[n]] + 2;//all in a single group
         for(i=1;i<=n  &&  sum[i] < sum[n];i++)
        {
            if(sum[i])ans=min(ans, dpPW[sum[i]] + dpPW[sum[n]-sum[i]] + 1);//partitioned in 2 groups;
        }
         ans=min(ans, Check(n));//partitioned in 3 groups
         cout << ans << '\n';
    }
    return 0;
}