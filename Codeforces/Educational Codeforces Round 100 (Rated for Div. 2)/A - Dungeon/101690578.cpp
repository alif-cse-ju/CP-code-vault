#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int a,b,c,t,sum;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        sum=a+b+c;
        if(a >= sum/9  &&  b >= sum/9  &&  c >= sum/9  &&  (a+b+c)%9 == 0)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;