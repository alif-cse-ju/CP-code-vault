#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    char c;
    bool ok;
    int i,l,t;
    string a,b;
    cin >> t;
    while(t--)
    {
        cin >> l >> a >> b;
        vector<int>diffs;
        vector<vector<int> >ans;
        for(i=0;i<l;i++)
        {
            if(a[i] < b[i])
            {
                cout << "-1\n";
                break;
            }
        }
        if(i < l)continue;
        for(c='z';c>='a';c--)
        {
            ok=false;
            diffs.clear();
            for(i=0;i<l;i++)
            {
                if(b[i] == c  &&  a[i] != c)diffs.emplace_back(i);
            }
            if(!diffs.empty())
            {
                for(i=0;i<l;i++)
                {
                    if(a[i] == c)
                    {
                        ok=true;
                        diffs.emplace_back(i);
                        break;
                    }
                }
            }
            if(!ok  &&  !diffs.empty())
            {
                cout << "-1\n";
                break;
            }
            if(!diffs.empty())ans.emplace_back(diffs);
            for(int x : diffs)a[i]=c;
        }
        if(c >= 'a')continue;
        cout << ans.size() << '\n';
        for(vector<int>v : ans)
        {
            cout << v.size();
            for(int x : v)cout << ' ' << x;
            cout << '\n';
        }
    }
    return 0;
}