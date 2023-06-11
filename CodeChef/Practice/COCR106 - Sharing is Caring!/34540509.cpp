#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int n,t;
    LL i,x,ans,sum;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=sum=0;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            sum+=x;
            ans=max(ans,(sum+i-1)/i);
        }
        cout << ans << '\n';
    }
    return 0;
}