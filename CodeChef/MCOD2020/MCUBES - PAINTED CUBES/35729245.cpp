#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,n,x,y=0,cnt=0;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        if(x == y)++cnt;
        else cnt=1;
        y=x;
    }
    cout << n-cnt+1;
    return 0;
}