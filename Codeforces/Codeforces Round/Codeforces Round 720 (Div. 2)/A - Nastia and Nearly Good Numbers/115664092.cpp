#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long long a,b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(b == 1)cout << "NO\n";
        else cout << "YES\n" << a << ' ' << a*b << ' ' << a*(b+1) << '\n';
    }
    return 0;