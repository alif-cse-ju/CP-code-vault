#include<bits/stdc++.h>
using namespace std;
int cnt[26];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,t;
    string a,b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        memset(cnt,0,sizeof(cnt));
        for(char c : a)++cnt[c-'a'];
        sort(a.begin(),a.end());
        if(cnt[0]  &&  cnt[1]  &&  cnt[2]  &&  b == "abc")
        {
            while(cnt[0]--)cout << 'a';
            while(cnt[2]--)cout << 'c';
            while(cnt[1]--)cout << 'b';
            for(i=3;i<26;i++)
            {
                while(cnt[i]--)cout << (char)('a'+i);
            }
            cout << '\n';
        }
        else cout << a << '\n';
    }
    return 0;