#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool flag=0;
    int h,n,x,y;
    cin >> n >> h >> x;
    while(n--)
    {
        cin >> y;
        flag |= (x+y >= h);
    }
    cout << (flag ? "YES" : "NO");
    return 0;
}
//