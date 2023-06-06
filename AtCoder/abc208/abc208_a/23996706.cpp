#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin >> a >> b;
    if(a*6 >= b  &&  a <= b)cout << "Yes";
    else cout << "No";
    return 0;
}
