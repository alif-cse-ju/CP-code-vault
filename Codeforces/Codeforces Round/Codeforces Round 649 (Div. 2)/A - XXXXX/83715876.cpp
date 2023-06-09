#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,l,n,r,t,x,y,cnt,sum;
    cin >> t;
    while(t--)
    {
        l=r=cnt=sum=0;
        cin >> n >> x;
        for(i=1;i<=n;i++)
        {
            cin >> y;
            sum+=y;
            if(y%x == 0)++cnt;
            else
            {
                if(l == 0)l=r=i;
                else r=i;
            }
        }
        if(cnt == n)cout << "-1\n";
        else if(sum%x > 0)cout << n << '\n';
        else cout << n-min(n-r+1,l) << '\n';
    }
    return 0;