#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int N=5e5;
LL ans[N+5];
void PreCal()
{
    int i,j;
    for(i=1;i<=N;i++)
    {
        for(j=2*i;j<=N;j+=i)ans[j]+=i;
    }
}
int main()
{
    FAST();
    int n,t;
    PreCal();
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << ans[n] << '\n';
    }
    return 0;
}