#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,v;
    cin >> v >> a >> b >> c;
    v %= (a+b+c);
    if(v < a)cout << "F";
    else if(v < a+b)cout << "M";
    else cout << "T";
    return 0;
}
