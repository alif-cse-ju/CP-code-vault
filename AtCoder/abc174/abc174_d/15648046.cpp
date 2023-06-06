#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    char s[200005];
    int i,l,ans=0,cnt=0;
    cin >> l >> s+1;
    for(i=1;i<=l;i++)cnt+=(s[i] == 'W');
    while(cnt--)
    {
        ans+=(s[l--] == 'R');
    }
    cout << ans;
    return 0;
}
