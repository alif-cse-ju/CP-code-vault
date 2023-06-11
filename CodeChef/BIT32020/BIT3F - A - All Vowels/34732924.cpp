#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    string s;
    int i,l,t,x,y,ans;
    vector<int>vowels={1,5,9,15,21};
    cin >> t;
    while(t--)
    {
        cin >> s;
        ans=0;
        for(char c : s)
        {
            x=INT_MAX;
            y=c-'a'+1;
            for(int it : vowels)x=min(x,abs(it-y));
            ans+=x;
        }
        cout << ans << '\n';
    }
    return 0;
}