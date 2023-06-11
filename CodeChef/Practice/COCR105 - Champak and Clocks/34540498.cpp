#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,l,r,t,ans;
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> l >> r;
        for(i=l;i<r;i++)
        {
            if(i == 2  ||  i == 8  ||  i == 14  ||  i == 20)++ans;
            else ans+=2;
        }
        if(i == 3  ||  i == 9  ||  i == 15  ||  i == 21)++ans;
        cout << ans << '\n';
    }
    return 0;
}