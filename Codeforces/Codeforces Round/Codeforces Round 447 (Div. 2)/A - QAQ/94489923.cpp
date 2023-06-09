#include<bits/stdc++.h>
using namespace std;
const int N=105;
char s[N];
int F[N],R[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,ans=0;
    cin >> s+1;
    l=strlen(s+1);
    for(i=1;i<=l;i++)F[i]=F[i-1]+(s[i] == 'Q');
    for(i=l;i>0;i--)R[i]=R[i+1]+(s[i] == 'Q');
    for(i=2;i<l;i++)
    {
        if(s[i] == 'A')ans+=F[i]*R[i];
    }
    cout << ans;
    return 0;