#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    char c;
    string s,ans;
    vector<int>temp;
    int i,n,t,x,a[55],cnt[30];
    cin >> t;
    while(t--)
    {
        ans="";
        cin >> s >> n;
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<n;i++)cin >> a[i],ans+='0';
        for(char c : s)++cnt[c-'a'];
        while(true)
        {
            for(i=0;i<n;i++)
            {
                if(a[i] == 0)temp.emplace_back(i);
            }
            x=temp.size();
            if(x == 0)break;
            for(c='z';c>='a';c--)
            {
                if(cnt[c-'a'] >= x)break;
                cnt[c-'a']=0;
            }
            cnt[c-'a']=0;
            while(!temp.empty())
            {
                x=temp.back();temp.pop_back();
                ans[x]=c;
                for(i=0;i<n;i++)
                {
                    if(a[i] > 0)a[i]-=abs(i-x);
                }
                a[x]=-1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}