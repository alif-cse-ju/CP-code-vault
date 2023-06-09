#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int t;
    LL a,b,c;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        if(a >= c)cout << "-1 " << b << '\n';
        else if(a*b <= c)cout << "1 -1\n";
        else cout << "1 " << b << '\n';
    }
    return 0;