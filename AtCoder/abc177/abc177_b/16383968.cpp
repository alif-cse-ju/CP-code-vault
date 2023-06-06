#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string a,b;
    int i,j,la,lb,ans=INT_MAX,cnt;
    cin >> a >> b;
    la=a.size(),lb=b.size();
    for(i=0;i<=la-lb;i++)
    {
        cnt=0;
        for(j=0;j<lb;j++)cnt+=a[j+i] != b[j];
        ans=min(ans,cnt);
    }
    cout << ans;
    return 0;
}
