#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int ans[N];
bool mark[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,q,v1,v2,x,y;
    cin >> n;
    q=n;
    while(q--)
    {
        if(q)
        {
            x=y=0;
            for(i=1;i<=n;i++)
            {
                if(!ans[i])
                {
                    if(!x)x=i;
                    else
                    {
                        y=i;
                        cout << "? " << x << ' ' << y << endl;
                        cin >> v1;
                        cout << "? " << y << ' ' << x << endl;
                        cin >> v2;
                        if(v1 > v2)
                        {
                            ans[x]=v1;
                            mark[v1]=1;
                        }
                        else
                        {
                            ans[y]=v2;
                            mark[v2]=1;
                        }
                        break;
                    }
                }
            }
        }
        else
        {
            for(i=1;i<=n;i++)
            {
                if(!ans[i])x=i;
                if(!mark[i])y=i;
            }
            ans[x]=y;
        }
    }
    cout << "!";
    for(i=1;i<=n;i++)cout << ' ' << ans[i];
    return 0;
}