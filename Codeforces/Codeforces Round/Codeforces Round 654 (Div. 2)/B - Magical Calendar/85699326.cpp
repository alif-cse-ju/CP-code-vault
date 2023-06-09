#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int t;
    LL m,n,x,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        x=min(m+1,n);
        ans=(x*(x-1))/2+(n <= m);
        cout << ans << '\n';
    }
    return 0;