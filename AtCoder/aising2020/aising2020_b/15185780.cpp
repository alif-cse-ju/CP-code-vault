#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int i,n,x,ans=0;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        if((i & 1)  &&  (x & 1))++ans;
    }
    cout << ans;
    return 0;
}
