#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    FAST();
    int t,ans;
    long long n=2050,mx=1e18;
    vector<long long>v;
    while(n <= mx)
    {
        v.emplace_back(n);
        n*=10;
    }
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=0;
        while(n >= 2050)
        {
            ++ans;
            auto it=upper_bound(v.begin(),v.end(),n);
            n-=*(--it);
        }
        if(n)ans=-1;
        cout << ans << '\n';
    }
    return 0;
}