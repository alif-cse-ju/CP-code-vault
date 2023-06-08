#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
vector<int>cnt[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cnt[i].clear();
        for(i=1;i<=n;i++)
        {
            cin >> x;
            cnt[x].emplace_back(i);
        }
        x=-1;
        for(i=1;i<=n;i++)
        {
            if((int)cnt[i].size() == 1)
            {
                x=cnt[i][0];
                break;
            }
        }
        cout << x << '\n';
    }
    return 0;