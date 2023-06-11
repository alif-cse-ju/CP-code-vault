#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int n,t,x,cnt[3];
    cin >> t;
    while(t--)
    {
        cin >> n;
        queue<int>q;
        while(n--)
        {
            cin >> x;
            q.emplace(x);
        }
        memset(cnt,0,sizeof(cnt));
        while(!q.empty())
        {
            x=q.front();q.pop();
            if(x == 5)++cnt[1];
            else if(x == 10)
            {
                if(!cnt[1]){q.emplace(x);break;}
                --cnt[1],++cnt[2];
            }
            else
            {
                if(cnt[2])--cnt[2];
                else if(cnt[1] > 1)cnt[1]-=2;
                else {q.emplace(x);break;}
            }
        }
        if(q.empty())cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}