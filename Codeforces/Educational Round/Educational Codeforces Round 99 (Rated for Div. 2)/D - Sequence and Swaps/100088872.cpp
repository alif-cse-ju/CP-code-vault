#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;
const int mod=1e9+7;
int n,a[N];
bool Check()
    for(int i=2;i<=n;i++)
    {
        if(a[i] < a[i-1])return 1;
    }
    return 0;
int Solve()
    int i,x,ans=0;
    cin >> n >> x;
    for(i=1;i<=n;i++)cin >> a[i];
    while(Check())
    {
        for(i=1;i<=n;i++)
        {
            if(a[i] > x)break;
        }
        if(i > n)break;
        swap(a[i],x);
        ++ans;
    }
    return (Check() ? -1 : ans);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)cout << Solve() << '\n';
    return 0;
}