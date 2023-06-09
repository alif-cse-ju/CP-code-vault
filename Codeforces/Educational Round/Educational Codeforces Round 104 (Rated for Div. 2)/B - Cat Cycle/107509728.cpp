#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,n,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        --k;
        cout << 1+(k+(n & 1 ? k/(n/2) : 0))%n << '\n';
    }
    return 0;