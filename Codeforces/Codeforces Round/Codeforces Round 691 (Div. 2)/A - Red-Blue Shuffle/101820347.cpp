#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,t,blue,red;
    string a,b;
    cin >> t;
    while(t--)
    {
        cin >> l >> a >> b;
        blue=red=0;
        for(i=0;i<l;i++)
        {
            if(a[i] > b[i])++red;
            else if(a[i] < b[i])++blue;
        }
        if(red == blue)cout << "EQUAL\n";
        else if(red > blue)cout << "RED\n";
        else cout << "BLUE\n";
    }
    return 0;