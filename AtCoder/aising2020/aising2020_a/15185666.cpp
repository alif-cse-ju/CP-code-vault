#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int l,r,d;
    cin >> l >> r >> d;
    cout << r/d-(l-1)/d;
    return 0;
}
