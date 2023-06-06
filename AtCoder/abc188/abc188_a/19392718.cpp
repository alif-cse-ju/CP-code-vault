#include<bits/stdc++.h>

using namespace std;

const int N=4e5+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int x,y;
    cin >> x >> y;
    if(min(x,y)+3 > max(x,y))cout << "Yes";
    else cout << "No";
    return 0;
}