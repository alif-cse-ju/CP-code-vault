#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int l,ans=0,cnt[3]={0};
    cin >> s;
    for(char c : s)++cnt[(c-'0')%3],ans+=(c-'0');
    l=(int)s.size();
    ans%=3;
    if(ans == 0)cout << "0";
    else if(ans == 1)
    {
        if(cnt[1] > 0  &&  l > 1)cout << "1";
        else if(cnt[2] > 1  &&  l > 2)cout << "2";
        else cout << "-1";
    }
    else
    {
        if(cnt[2] > 0  &&  l > 1)cout << "1";
        else if(cnt[1] > 1  &&  l > 2)cout << "2";
        else cout << "-1";
    }
    return 0;
}
