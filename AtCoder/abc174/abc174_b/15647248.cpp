#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int n,ans=0;
    double d,x,y;
    cin >> n >> d;
    while(n--)
    {
        cin >> x >> y;
        if(sqrt(x*x+y*y) <= d)++ans;
    }
    cout << ans;
    return 0;
}
