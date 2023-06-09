#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 2)
        {
            cout << "2\n";
            cout << "1 2\n";
        }
        else
        {
            vector<int>v;
            vector<pair<int,int>>ans;
            for(i=1;i<=n;i++)v.emplace_back(i);
            x=v[n-1],y=v[n-3];
            v[n-3]=(x+y)/2;
            ans.emplace_back(x,y);
            v.pop_back();
            while(v.size() > 1)
            {
                x=v.back(),v.pop_back();
                y=v.back(),v.pop_back();
                v.emplace_back((x+y)/2);
                ans.emplace_back(y,x);
            }
            cout << v[0] << '\n';
            for(auto it : ans)
            {
                cout << it.first << ' ' << it.second << '\n';
            }
        }
    }
    return 0;
}