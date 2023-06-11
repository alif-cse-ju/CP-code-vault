#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
char a[N],b[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,t,la,lb,mx,cnt[30];
    cin >> t;
    while(t--)
    {
        cin >> a+1 >> b+1;
        la=strlen(a+1),lb=strlen(b+1);
        mx=0,memset(cnt,0,sizeof(cnt));
        for(i=1;i<la;i++)++cnt[a[i]-'a'];
        for(i=0;i<26;i++)mx=max(mx,cnt[i]);
        cout << mx;
        if(a[la] == 'n')cout << " north ";
        else if(a[la] == 's')cout << " south ";
        else if(a[la] == 'e')cout << " east ";
        else cout << " west ";
        mx=0,memset(cnt,0,sizeof(cnt));
        for(i=1;i<lb;i++)++cnt[b[i]-'a'];
        for(i=0;i<26;i++)mx=max(mx,cnt[i]);
        cout << mx;
        if(b[lb] == 'n')cout << " north\n";
        else if(b[lb] == 's')cout << " south\n";
        else if(b[lb] == 'e')cout << " east\n";
        else cout << " west\n";
    }
    return 0;
}