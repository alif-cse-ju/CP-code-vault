#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    string s;
    cin >> s;
    if(s[0] <= 'Z')cout << "A";
    else cout << "a";
    return 0;
}
