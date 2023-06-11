#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,t,x,cnt;
    bool mark[26];
    cin >> t;
    while(t--)
    {
        cin >> x >> s;
        cnt=0;
        memset(mark,0,sizeof(mark));
        for(char c : s)
        {
            if(c <= 'Z')mark[c-'A']=1;
            else mark[c-'a']=1;
        }
        for(i=0;i<26;i++)cnt+=mark[i];
        if(cnt & 1)cout << "AVENGER\n";
        else cout << "SPAM\n";
    }
    return 0;
}
//