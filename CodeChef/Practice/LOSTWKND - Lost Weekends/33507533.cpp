#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,t,x,cnt;
    cin >> t;
    while(t--)
    {
        cnt=0;
        for(i=0;i<5;i++)cin >> x,cnt+=x;
        cin >> x,cnt*=x;
        if(cnt <= 5*24)cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}