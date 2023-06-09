#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x,y,cnt[102];
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<n;i++)
        {
            cin >> x;
            ++cnt[x];
        }
        x=y=-1;
        for(i=0;i<102;i++)
        {
            if(!cnt[i])
            {
                if(x == -1)x=y=i;
                else y=i;
                break;
            }
            else if(cnt[i] == 1)
            {
                if(x == -1)x=i;
            }
        }
        cout << x+y << '\n';
    }
    return 0;