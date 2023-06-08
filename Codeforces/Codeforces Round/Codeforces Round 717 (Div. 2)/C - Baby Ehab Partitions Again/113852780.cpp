#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int n,a[102],dp[102][M],pos;
int DP(int cur,int sum)
    if(cur > n)return sum == 0;
    int &ans=dp[cur][sum];
    if(ans >= 0)return ans;
    ans=DP(cur+1+(cur+1 == pos),sum);
    if(a[cur] <= sum)ans |= DP(cur+1+(cur+1 == pos),sum-a[cur]);
    return ans;
int main()
    FAST();
    int i,sum=0;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    if(sum & 1)cout << "0";
    else
    {
        memset(dp,-1,sizeof(dp));
        if(DP(1,sum/2))
        {
            cout << "1\n";
            for(i=1;i<=n;i++)
            {
                if(a[i] & 1)
                {
                    cout << i;
                    return 0;
                }
            }
            for(i=1;i<=n;i++)
            {
                pos=i;
                if(!DP(1,(sum-a[i])/2))
                {
                    cout << i;
                    return 0;
                }
            }
        }
        else cout << "0\n";
    }
    return 0;
}