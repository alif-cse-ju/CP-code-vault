#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t;
    long long cnt;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        sort(a+1,a+n+1);
        cnt=0;
        for(i=1;i<=n  &&  a[i] <= i;i++)cnt+=i-a[i];
        if((i > n)  &&  (cnt & 1))cout << "First\n";
        else cout << "Second\n";
    }
    return 0;
}
//