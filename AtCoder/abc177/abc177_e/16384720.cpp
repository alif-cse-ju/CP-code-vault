#include<bits/stdc++.h>

using namespace std;

const int N=1e6;
int a[N+2],cnt[N+2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,x,temp,gcd=0;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        ++cnt[x];
        gcd=__gcd(x,gcd);
    }
    if(gcd > 1)
    {
        cout << "not coprime";
        return 0;
    }
    for(i=2;i<=N;i++)
    {
        temp=0;
        for(j=i;j<=N;j+=i)temp+=cnt[j];
        if(temp > 1)
        {
            cout << "setwise coprime";
            return 0;
        }
    }
    cout << "pairwise coprime";
    return 0;
}
