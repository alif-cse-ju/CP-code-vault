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
{
    FAST();
    int t;
    long long n,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans=0;
        if(n%4 == 1)ans=20;
        else if(n%4 == 2)ans=36;
        else if(n%4 == 3)ans=51;
        if(n/4)ans+=4ll*(4-n%4);
        n/=4;
        ans+=n*44;
        cout << ans << '\n';
    }
    return 0;
}