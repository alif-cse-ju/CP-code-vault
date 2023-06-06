#include<bits/stdc++.h>

using namespace std;

const int N=1e3+5;
const int mod=998244353;

int v[N],p[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,x,sum=0;
    cin >> n >> x;
    for(i=1;i<=n;i++)cin >> v[i] >> p[i];
    for(i=1;i<=n;i++)
    {
        sum+=v[i]*p[i];
        if(sum > x*100)
        {
            cout << i;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}