#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,j,l,t;
    string a,b;
    cin >> t;
    while(t--)
    {
        cin >> l >> a >> b;
        vector<int>ans;
        for(i=l-1;i>0;i--)
        {
            if(a[i] == b[i])continue;
            if(a[0] == b[i])
            {
                ans.emplace_back(1);
                if(a[0] == '0')a[0]='1';
                else a[0]='0';
            }
            for(j=0;j<=i;j++)
            {
                if(a[j] == '0')a[j]='1';
                else a[j]='0';
            }
            for(j=0;j<=i/2;j++)swap(a[j],a[i-j]);
            ans.emplace_back(i+1);
        }
        if(a[0] != b[0])ans.emplace_back(1);
        cout << (int)ans.size() << ' ';
        for(int x : ans)cout << x << ' ';
        cout << '\n';
    }
    return 0;
}