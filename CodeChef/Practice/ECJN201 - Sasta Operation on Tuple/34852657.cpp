#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int t;
    LL a,b,c,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        cin >> x >> y >> z;
        if(x < a  ||  y < b  ||  z < c)cout << "-1\n";
        else cout << (x-a)+(y-b)+(z-c) << '\n';
    }
    return 0;
}