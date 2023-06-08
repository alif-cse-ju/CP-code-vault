#include<bits/stdc++.h>
using namespace std;
int ans[102];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cur,i,j,k,n,x;
    cin>> n;
    for(i=cur=n;i;i--)
    {
        if(!ans[i])
        {
            vector<pair<int,int>>v;
            for(j=2; ;j++)
            {
                cout << '?';
                for(k=1;k<=n;k++)
                {
                    if(i == k)cout << ' ' << j;
                    else cout << " 1";
                }
                cout << endl;
                cin >> x;
                if(!x  ||  x == i)
                {
                    ans[i]=cur-j+2, --cur;
                    for(auto [id,d] : v)ans[id]=ans[i]+d, --cur;
                    break;
                }
                else if(ans[x])
                {
                    ans[i]=ans[x]-j+2, --cur;
                    for(auto [id,d] : v)ans[id]=ans[i]+d, --cur;
                    break;
                }
                else v.emplace_back(x,j-1);
                if(j == cur)
                {
                    ans[i]=cur-j+1, --cur;
                    for(auto [id,d] : v)ans[id]=ans[i]+d, --cur;
                    break;
                }
            }
        }
    }
    cout << '!';
    for(i=1;i<=n;i++)cout << ' ' << ans[i];
    cout << endl;
    return 0;
}