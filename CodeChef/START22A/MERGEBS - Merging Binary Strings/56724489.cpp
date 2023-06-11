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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
const int sz=1005;
char a[sz],b[sz];
int cnta0[sz],cnta1[sz],cntb0[sz],cntb1[sz],dp[sz][sz],l;
int DP(int i,int j)
{
    if(j > l)return 0;
    if(i > l)return cntb0[j]*cnta1[l];
    int &ans=dp[i][j];
    if(ans > -1)return ans;
    ans=DP(i+1,j);
    if(b[j] == '0')ans=min(ans, cnta1[i] + DP(i,j+1));
    else ans=min(ans, cnta0[i+1] + DP(i,j+1));
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a1,b1,ans,i,j,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> a+1 >> b+1;
        a1=b1=ans=0;
        for(i=1;i<=l;i++)
        {
            cnta1[i] = cnta1[i-1];
            if(a[i] == '0')ans += a1;
            else ++a1, ++cnta1[i];
            cntb1[i] = cntb1[i-1];
            if(b[i] == '0')ans += b1;
            else ++b1, ++cntb1[i];
        }
        cnta0[l+1]=cntb0[l+1]=0;
        for(i=l;i;i--)
        {
            cnta0[i] = cnta0[i+1];
            cntb0[i] = cntb0[i+1];
            if(a[i] == '0')++cnta0[i];
            if(b[i] == '0')++cntb0[i];
        }
        for(i=0;i<=l;i++)
        {
            for(j=1;j<=l;j++)dp[i][j]=-1;
        }
        cout << ans + DP(0,1) << '\n';
    }
    return 0;
}