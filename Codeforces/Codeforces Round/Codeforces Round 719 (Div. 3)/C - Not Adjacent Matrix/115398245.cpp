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
    int i,j,n,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 2)cout << "-1\n";
        else
        {
            ans=-1;
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    ans+=2;
                    if(ans > n*n)ans=2;
                    cout << ans << ' ';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}