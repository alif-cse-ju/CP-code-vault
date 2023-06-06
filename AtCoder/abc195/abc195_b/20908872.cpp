#include<bits/stdc++.h>

using namespace std;

const int N=2e6+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,mn,mx,w;
    cin >> a >> b >> w;
    w*=1000;
    mx=w/a;
    if(a+((w%a)+mx-1)/mx > b)
    {
        cout << "UNSATISFIABLE";
        return 0;
    }
    mn=w/b;
    w%=b;
    if(w)
    {
        if(w+(b-a)*mn < a)
        {
            cout << "UNSATISFIABLE";
            return 0;
        }
        else ++mn;
    }
    cout << mn << ' ' << mx;
    return 0;
}
//