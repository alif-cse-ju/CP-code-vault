#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(n%k)cout << n/k+1 << ' ' << n%k << '\n';
        else cout << n/k << ' ' << k << '\n';
    }
    return 0;
}
//