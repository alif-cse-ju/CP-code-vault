#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int a,b,c,n,ans;
    cin >> a >> b >> c >> n;
    ans=min(a,n),n-=ans;
    n-=min(b,n);
    ans-=min(c,n);
    cout << ans;
    return 0;
}
