#include<bits/stdc++.h>
using namespace std;
const int N=3e2+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s[N];
    int i,j,k,l,n,r,t,cnt[3][2];
    cin >> t;
    while(t--)
    {
        cin >> n;
        k=0;
        for(i=0;i<3;i++)cnt[i][0]=cnt[i][1]=0;
        for(i=0;i<n;i++)
        {
            cin >> s[i];
            for(j=0;j<n;j++)
            {
                l=(i+j)%3;
                if(s[i][j] == 'X')++k,++cnt[l][0];
                else if(s[i][j] == 'O')++k,++cnt[l][1];
            }
        }
        for(l=0;l<3;l++)
        {
            for(r=0;r<3;r++)
            {
                if(l == r)continue;
                if(cnt[l][0]+cnt[r][1] <= k/3)
                {
                    for(i=0;i<n;i++)
                    {
                        for(j=0;j<n;j++)
                        {
                            if((i+j)%3 == l  &&  s[i][j] == 'X')s[i][j]='O';
                            else if((i+j)%3 == r  &&  s[i][j] == 'O')s[i][j]='X';
                        }
                        cout << s[i] << '\n';
                    }
                    break;
                }
            }
            if(r < 3)break;
        }
    }
    return 0;
}