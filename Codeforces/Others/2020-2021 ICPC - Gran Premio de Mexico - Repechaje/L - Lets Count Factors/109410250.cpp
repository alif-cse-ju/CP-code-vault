#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
const int mod=1e9+7;
int cnt[N];
bool mark[N];
void PreCal()
    int i,j;
    for(i=2;i<N;i+=2)++cnt[i];
    for(i=3;i<N;i+=2)
    {
        if(!mark[i])
        {
            for(j=i;j<N;j+=i)++cnt[j],mark[j]=1;
        }
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    int t,m,n,gcd;
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        gcd=__gcd(m,n);
        cout << cnt[m]+cnt[n]-cnt[gcd] << '\n';
    }
    return 0;