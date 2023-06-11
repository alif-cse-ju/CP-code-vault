#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long long a,b,c,e,ee,h,hh,i,n,ans,temp;
    cin >> t;
    while(t--)
    {
        cin >> n >> e >> h >> a >> b >> c;
        ans=LLONG_MAX;
        for(i=0;i<=min({e,h,n});i++)
        {
            temp=i*c;
            ee=(e-i)/2;
            hh=(h-i)/3;
            if(i+ee+hh >= n)
            {
                if(a <= b)
                {
                    temp+=min(ee,n-i)*a;
                    temp+=max(0ll,n-i-ee)*b;
                }
                else
                {
                    temp+=min(hh,n-i)*b;
                    temp+=max(0ll,n-i-hh)*a;
                }
                ans=min(ans,temp);
            }
        }
        if(ans == LLONG_MAX)cout << "-1\n";
        else cout << ans << '\n';
    }
    return 0;
}
//