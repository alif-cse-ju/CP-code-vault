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
const int M=1030;
const int N=1e6+5;
const int mod=998244353;
int cnt[10][52],dp[52][M],idx[10][52][2],n;
int DP(int ch,int mask)
    int &ans=dp[ch][mask];
    if(ans > -1)return ans;
    bool ok;
    int i,j,last,mx=0,newMask;
    for(i=0;i<52;i++)
    {
        newMask=0,ok=1;
        for(j=0;j<n;j++)
        {
            if((mask >> j) & 1)last=idx[j][ch][1];
            else last=idx[j][ch][0];
            if(idx[j][i][0] > last)continue;
            else if(idx[j][i][1] > last)newMask |= (1 << j);
            else
            {
                ok=0;
                break;
            }
        }
        if(ok)mx=max(mx,DP(i,newMask));
    }
    return ans=mx+1;
}
 void Print(int cur,int ch,int mask)
{
    if(ch < 26)cout << (char)('A'+ch);
    else cout << (char)('a'+(ch-26));
    if(cur == 1)return;
    bool ok;
    int i,j,last,newMask;
    for(i=0;i<52;i++)
    {
        newMask=0,ok=1;
        for(j=0;j<n;j++)
        {
            if((mask >> j) & 1)last=idx[j][ch][1];
            else last=idx[j][ch][0];
            if(idx[j][i][0] > last)continue;
            else if(idx[j][i][1] > last)newMask |= (1 << j);
            else
            {
                ok=0;
                break;
            }
        }
        if(ok  &&  DP(i,newMask) == cur-1)
        {
            Print(cur-1,i,newMask);
            return;
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok;
    string s;
    int ans,i,j,l,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(dp,-1,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        memset(idx,-1,sizeof(idx));
        for(i=0;i<n;i++)
        {
            cin >> s;
            l=(int)s.size();
            for(j=0;j<l;j++)
            {
                if(s[j] >= 'a')idx[i][s[j]-71][cnt[i][s[j]-71]]=j, ++cnt[i][s[j]-71];
                else idx[i][s[j]-65][cnt[i][s[j]-65]]=j, ++cnt[i][s[j]-65];
            }
        }
        ans=0;
        for(i=0;i<52;i++)
        {
            ok=1;
            for(j=0;j<n;j++)ok &= (cnt[j][i] > 0);
            if(ok)ans=max(ans,DP(i,0));
        }
        cout << ans << '\n';
        if(ans)
        {
            for(i=0;i<52;i++)
            {
                ok=1;
                for(j=0;j<n;j++)ok &= (cnt[j][i] > 0);
                if(ok  &&  DP(i,0) == ans)
                {
                    Print(ans,i,0);
                    break;
                }
            }
        }
        cout << '\n';
    }
    return 0;
}