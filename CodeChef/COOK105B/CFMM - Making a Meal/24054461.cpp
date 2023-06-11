#include<bits/stdc++.h>
using namespace std;
int mark[27];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,l,t,n,ans=0;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(mark,0,sizeof(mark));
        while(n--)
        {
            cin >> s;
            l=s.size();
            for(i=0;i<l;i++)
            {
                mark[s[i]-96]++;
            }
        }
        ans=min(mark[3]/2,mark[5]/2);
        ans=min(ans,mark[4]);
        ans=min(ans,mark[6]);
        ans=min(ans,mark[8]);
        ans=min(ans,mark[15]);
        cout << ans << endl;
    }
    return 0;
}