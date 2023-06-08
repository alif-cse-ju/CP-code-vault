#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=3e5+5;
const int mod=1e9+7;
char a[N],b[N];
int cnt0[N],cnt1[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool tgl;
    int i,l,t;
    cin >> t;
    while(t--)
    {
        cin >> l >> a+1 >> b+1;
        for(i=1;i<=l;i++)
        {
            cnt0[i]=cnt0[i-1]+(a[i] == '0');
            cnt1[i]=cnt1[i-1]+(a[i] == '1');
        }
        tgl=0;
        for(i=l;i;i--)
        {
            if(tgl)
            {
                if(a[i] == b[i])
                {
                    if(cnt0[i] == cnt1[i])tgl=0;
                    else break;
                }
            }
            else
            {
                if(a[i] != b[i])
                {
                    if(cnt0[i] == cnt1[i])tgl=1;
                    else break;
                }
            }
        }
        if(i)cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
//