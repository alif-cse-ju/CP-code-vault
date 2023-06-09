#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,t,x,o,e;
    bool mark[105];
    cin >> t;
    while(t--)
    {
        o=e=0;
        cin >> n;
        for(i=1;i<101;i++)mark[i]=0;
        for(i=0;i<n;i++)
        {
            cin >> x;
            mark[x]=1;
            if(x & 1)o++;
            else e++;
        }
        if(e%2 == 0)cout << "YES\n";
        else
        {
            for(i=1;i<100;i+=2)
            {
                if(mark[i])
                {
                    if(mark[i-1]  ||  mark[i+1])
                    {
                        cout << "YES\n";
                        break;
                    }
                }
            }
            if(i > 100)cout << "NO\n";
        }
    }
    return 0;
}