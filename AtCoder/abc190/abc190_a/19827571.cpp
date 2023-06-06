#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int a,b,c;
    cin >> a >> b >> c;
    if(a > b)cout << "Takahashi";
    else if(a < b)cout << "Aoki";
    else
    {
        if(c)cout << "Takahashi";
        else cout << "Aoki";
    }
    return 0;
}