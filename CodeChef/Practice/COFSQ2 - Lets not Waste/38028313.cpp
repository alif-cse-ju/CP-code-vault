#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long a,b,c=0;
    cin >> a >> b;
    if((a & 1)  ||  b > a)cout << "-1";
    else
    {
        while(a != b  &&  a >= 0  &&  b >= 0)a-=2,--b,++c;
        if(a == b)cout << a/2 << ' ' << c << '\n' << "Rs. " << 110*a+120*c;
        else cout << "-1";
    }
    return 0;
}