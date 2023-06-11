#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,p,q,t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> p >> q;
        if(p%a  ||  q%b)cout << "NO\n";
        else
        {
            p/=a, q/=b;
            if(abs(p-q) < 2)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}