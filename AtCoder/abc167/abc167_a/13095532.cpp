#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    string a,b;
    cin >> a >> b;
    b.pop_back();
    if(a == b)cout << "Yes";
    else cout << "No";
    return 0;
}
