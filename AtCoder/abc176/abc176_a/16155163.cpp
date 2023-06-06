#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,t,x;
    cin >> n >> x >> t;
    cout << ((n/x)+(n%x > 0))*t;
    return 0;
}