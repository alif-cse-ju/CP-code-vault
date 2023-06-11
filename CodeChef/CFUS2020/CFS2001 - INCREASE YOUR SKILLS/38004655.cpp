#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,t;
    long long a,d,k,n,cur,inc;
    cin >> t;
    while(t--)
    {
        cin >> a >> d >> k >> n >> inc;
        cur=a;
        for(i=2;i<=n;i++)
        {
            cur+=d;
            if(i%k == 0)d+=inc;
        }
        cout << cur << '\n';
    }
    return 0;
}