#include<bits/stdc++.h>
 using namespace std;
 const int N=2e5+5;
const int mod=1e9+7;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        cout << max(x+y,max(x,y)*2-1) << '\n';
    }
    return 0;
}