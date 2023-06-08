#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,l,t;
    char s[55],ans[55][55];
    cin >> t;
    while(t--)
    {
        cin >> l >> s+1;
        vector<int>v;
        for(i=1;i<=l;i++)
        {
            if(s[i] == '2')v.emplace_back(i);
        }
        if(!v.empty()  &&  (int)v.size() < 3)cout << "NO\n";
        else
        {
            cout << "YES\n";
            for(i=1;i<=l;i++)
            {
                for(j=1;j<=l;j++)
                {
                    if(i == j)ans[i][j]='X';
                    else ans[i][j]='=';
                }
            }
            if(!v.empty())
            {
                for(i=1;i<(int)v.size();i++)ans[v[i-1]][v[i]]='+',ans[v[i]][v[i-1]]='-';
                ans[v.back()][v[0]]='+',ans[v[0]][v.back()]='-';
            }
            for(i=1;i<=l;i++)
            {
                for(j=1;j<=l;j++)cout << ans[i][j];
                cout << '\n';
            }
        }
    }
    return 0;
}