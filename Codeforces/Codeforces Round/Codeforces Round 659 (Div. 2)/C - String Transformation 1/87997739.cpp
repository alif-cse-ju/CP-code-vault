#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    char mxC;
    string a,b;
    vector<int>v;
    int i,l,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> l >> a >> b;
        for(i=0;i<l;i++)
        {
            if(a[i] > b[i])break;
        }
        if(i < l)cout << "-1\n";
        else
        {
            ans=0;
            for(char c='a';c<'t';c++)
            {
                mxC='z';
                v.clear();
                for(i=0;i<l;i++)
                {
                    if(a[i] == c  &&   c!= b[i])
                    {
                        mxC=min(mxC,b[i]);
                        v.emplace_back(i);
                    }
                }
                if(!v.empty())
                {
                    ++ans;
                    for(int x : v)a[x]=mxC;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}