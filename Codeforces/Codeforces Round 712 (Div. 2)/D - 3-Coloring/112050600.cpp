#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,x;
    vector<pair<int,int>>ans[2];
    cin >> n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            ans[(i+j) & 1].emplace_back(i,j);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin >> x;
            if(x == 1)
            {
                if(!ans[0].empty())
                {
                    cout << "2 " << ans[0].back().first << ' ' << ans[0].back().second << endl;
                    ans[0].pop_back();
                }
                else
                {
                    cout << "3 " << ans[1].back().first << ' ' << ans[1].back().second << endl;
                    ans[1].pop_back();
                }
            }
            else if(x == 2)
            {
                if(!ans[1].empty())
                {
                    cout << "1 " << ans[1].back().first << ' ' << ans[1].back().second << endl;
                    ans[1].pop_back();
                }
                else
                {
                    cout << "3 " << ans[0].back().first << ' ' << ans[0].back().second << endl;
                    ans[0].pop_back();
                }
            }
            else
            {
                if(!ans[1].empty())
                {
                    cout << "1 " << ans[1].back().first << ' ' << ans[1].back().second << endl;
                    ans[1].pop_back();
                }
                else
                {
                    cout << "2 " << ans[0].back().first << ' ' << ans[0].back().second << endl;
                    ans[0].pop_back();
                }
            }
        }
    }
    return 0;
}
//