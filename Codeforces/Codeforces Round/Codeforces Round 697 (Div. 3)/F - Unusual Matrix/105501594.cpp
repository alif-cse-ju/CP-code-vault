#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int mod=1e9+7;
int n;
char s[N];
bool a[N][N],b[N][N];
bool Solve()
    int i,j,cnt;
    for(i=1;i<=n;i++)
    {
        if(a[1][i] != b[1][i])
        {
            for(j=1;j<=n;j++)a[j][i]=1-a[j][i];
        }
    }
    for(i=2;i<=n;i++)
    {
        cnt=0;
        for(j=1;j<=n;j++)cnt+=(a[i][j] != b[i][j]);
        if(cnt  &&  cnt < n)return 0;
    }
    return 1;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            cin >> s+1;
            for(j=1;j<=n;j++)a[i][j]=(s[j]-'0');
        }
        for(i=1;i<=n;i++)
        {
            cin >> s+1;
            for(j=1;j<=n;j++)b[i][j]=(s[j]-'0');
        }
        cout << (Solve() ? "YES\n" : "NO\n");
    }
    return 0;
}