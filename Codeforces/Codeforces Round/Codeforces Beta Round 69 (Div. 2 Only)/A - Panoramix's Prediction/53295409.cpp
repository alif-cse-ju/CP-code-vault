#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n,m;
    cin >> n >> m;
    if(n == 2)
    {
        if(m == 3)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    else
    {
        if(m & 1)
        {
            int i,x=n+2;
            bool flag;
            while(x <= m)
            {
                flag=0;
                for(i=3; i<=sqrt(x); i+=2)
                {
                    if(x%i == 0)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    if(x < m)
                    {
                        cout << "NO";
                        return 0;
                    }
                }
                x+=2;
            }
            if(flag == 0)
            {
                cout << "YES";
                return 0;
            }
        }
        cout << "NO";
    }
    return 0;
}