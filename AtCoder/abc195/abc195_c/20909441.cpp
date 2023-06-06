#include<bits/stdc++.h>

using namespace std;

const int N=2e6+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,x,ans=0,cnt=-1,cur=0;
    cin >> n;
    while(n)
    {
        ++cnt;
        if(!cur)cur=9;
        else cur*=10;
        x=min(n,cur);
        ans+=(cnt/3)*x;
        n-=x;
    }
    cout << ans;
    return 0;
}
//