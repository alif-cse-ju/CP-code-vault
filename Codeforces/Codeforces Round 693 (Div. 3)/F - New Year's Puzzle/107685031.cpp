#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool flag;
    int i,m,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        set<int>st;
        map<int,bool>mark[3];
        while(m--)
        {
            cin >> x >> y;
            st.insert(y);
            mark[x][y]=1;
        }
        mark[1][0]=mark[1][n+1]=1;
        mark[2][0]=mark[2][n+1]=1;
        flag=1;
        x=y=0;
        st.insert(n+1);
        for(int it : st)
        {
            if(mark[1][it]  &&  mark[2][it])
            {
                if(x != y)
                {
                    if((it-x-1)%2  ||  (it-y-1)%2)
                    {
                        flag=0;
                        break;
                    }
                }
                x=y=it;
            }
            else if(mark[1][it])
            {
                if(x == y)y=it-1;
                else if((it-x-1)%2)
                {
                    flag=0;
                    break;
                }
                else y=it;
                x=it;
            }
            else
            {
                if(x == y)x=it-1;
                else if((it-y-1)%2)
                {
                    flag=0;
                    break;
                }
                else x=it;
                y=it;
            }
        }
        if(flag)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
//