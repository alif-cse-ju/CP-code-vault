#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int n,ans=1,mod;
    cin >> n;
    mod=7%n;
    while(mod > 0  &&  ans < n)
    {
        ++ans;
        mod=(mod*10+7)%n;
    }
    if(mod == 0)cout << ans;
    else cout << "-1";
    return 0;
}
