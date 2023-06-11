#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << 1;
        for(i=0;i<n;i++)cout << ' ' << (1ll << i);
        cout << '\n';
    }
    return 0;
}