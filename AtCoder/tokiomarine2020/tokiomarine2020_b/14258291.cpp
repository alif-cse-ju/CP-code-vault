#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    LL a,b,v,w,t;
    cin >> a >> v >> b >> w >> t;
    if(v < w)cout << "NO";
    else if(v == w)
    {
        if(a == b)cout << "YES";
        else cout << "NO";
    }
    else
    {
        w*=t,v*=t;
        if(v >= w+abs(a-b))cout << "YES";
        else cout << "NO";
    }
    return 0;
}
