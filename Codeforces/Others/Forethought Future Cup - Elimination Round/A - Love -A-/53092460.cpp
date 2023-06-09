#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,l,cnt=0;
    string s;
    cin >> s;
    l=s.size();
    for(i=0; i<l; i++)
    {
        if(s[i] == 'a')
        {
            cnt++;
        }
    }
    if(l%2 == 0)
    {
        if(cnt > l/2)
        {
            cout << l;
        }
        else
        {
            cout << min(cnt+cnt-1,l+1);
        }
    }
    else
    {
        if(cnt > (l-cnt))
        {
            cout << l;
        }
        else
        {
            cout << min(cnt+cnt-1,l+1);
        }
    }
    return 0;
}