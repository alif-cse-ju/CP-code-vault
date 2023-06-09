#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool flag;
    int i,l,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        if(x > y)cout << "NO\n";
        else
        {
            vector<int>vx,vy;
            for(i=0;i<30;i++)
            {
                if((x >> i) & 1)vx.emplace_back(i);
                if((y >> i) & 1)vy.emplace_back(i);
            }
            flag=1;
            if((int)vx.size() < (int)vy.size())flag=0;
            if(flag)
            {
                l=(int)vy.size();
                for(i=0;i<l;i++)
                {
                    if(vy[i] < vx[i])
                    {
                        flag=0;
                        break;
                    }
                }
            }
            if(flag)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
//