#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,x,y;
    long double ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        n <<= 1;
        vector<int>v1,v2;
        for(i=0;i<n;i++)
        {
            cin >> x >> y;
            if(!x)v1.emplace_back(abs(y));
            else v2.emplace_back(abs(x));
        }
        ans=0;
        n >>= 1;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        for(i=0;i<n;i++)ans+=sqrt(1.0*v1[i]*v1[i] + 1.0*v2[i]*v2[i]);
        cout << fixed << setprecision(15) << ans << '\n';
    }
    return 0;