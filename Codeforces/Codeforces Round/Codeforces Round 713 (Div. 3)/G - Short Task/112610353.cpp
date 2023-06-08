#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
const int M=1e7+5;
const int N=2e5+5;
const int mod=1e9+7;
int ans[M];
long long sum[M];
void PreCal()
    int i,j;
    ans[1]=1;
    for(i=2;i<M;i++)
    {
        for(j=i;j<M;j+=i)sum[j]+=i;
        if(sum[i]+1 < M  &&  !ans[sum[i]+1])ans[sum[i]+1]=i;
    }
int main()
    FAST();
    PreCal();
    int n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(ans[n])cout << ans[n] << '\n';
        else cout << "-1\n";
    }
    return 0;