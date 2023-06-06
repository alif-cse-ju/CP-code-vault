#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y;
    cin >> x >> y;
    if(x+y >= 15  &&  y >= 8)cout << '1';
    else if(x+y >= 10  &&  y >= 3)cout << '2';
    else if(x+y >= 3)cout << '3';
    else cout << '4';
    return 0;
}
//