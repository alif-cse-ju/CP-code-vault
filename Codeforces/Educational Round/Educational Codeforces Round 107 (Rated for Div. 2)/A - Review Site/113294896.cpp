#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    FAST();
    int n,t,x,ans;
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> n;
        while(n--)
        {
            cin >> x;
            if(x == 1  ||  x == 3)++ans;
        }
        cout << ans << '\n';
    }
    return 0;