#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,n,t,x,cnt;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt=0;
        for(i=0;i<n;i++)
        {
            cin >> x;
            cnt+=(x & 1);
        }
        if(cnt ==  n)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}