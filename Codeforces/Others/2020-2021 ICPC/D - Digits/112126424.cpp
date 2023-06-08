#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[M];
vector<int>ans;
long double lg[M],dp[M][12];
void DFS(int pos,int lastDigit)
    if(!pos)return;
    if(dp[pos-1][lastDigit] == dp[pos][lastDigit])DFS(pos-1,lastDigit);
    else
    {
        for(int j=0;j<12;j++)
        {
            if((j*a[pos])%10 == lastDigit  &&  dp[pos-1][j]+lg[pos] == dp[pos][lastDigit])
            {
                ans.emplace_back(a[pos]);
                DFS(pos-1,j);
                return;
            }
        }
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d,i,j,n;
    cin >> n >> d;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<10;j++)dp[i][j]=-1e10;
    }
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        lg[i]=log10(a[i]);
        for(j=0;j<12;j++)
        {
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            dp[i][(j*a[i])%10]=max(dp[i][(j*a[i])%10],dp[i-1][j]+lg[i]);
        }
    }
    if(n == 1)
    {
        if(a[1]%10 == d)cout << "1\n" << a[1];
        else cout << "-1";
        return 0;
    }
    if(dp[n][d] < 0)
    {
        cout << "-1";
        return 0;
    }
    DFS(n,d);
    cout << (int)ans.size() << '\n';
    for(int it : ans)cout << it << ' ';
    return 0;
}
//