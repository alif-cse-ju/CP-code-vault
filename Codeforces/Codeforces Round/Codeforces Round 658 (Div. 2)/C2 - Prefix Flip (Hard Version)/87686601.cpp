#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    bool flp;
    int i,l,n,r,t;
    char a[100002],b[100002];
    cin >> t;
    while(t--)
    {
        cin >> n >> a+1 >> b+1;
        flp=0,l=1,r=n;
        vector<int>ans;
        for(i=n;i>0;i--)
        {
            if(!flp)
            {
                if(a[r] == b[i])r--;
                else
                {
                    flp=!flp;
                    if(a[l] == b[i])ans.emplace_back(1);
                    ++l,ans.emplace_back(i);
                }
            }
            else
            {
                if(a[l] != b[i])l++;
                else
                {
                    flp=!flp;
                    if(a[r] != b[i])ans.emplace_back(1);
                    --r,ans.emplace_back(i);
                }
            }
        }
        cout << ans.size();
        for(int x : ans)cout << ' ' << x;
        cout << '\n';
    }
    return 0;
}