#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    FAST();
    long long j,k;
    int i,n,t,cur,sz;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(n < 62  &&  k > (1ll << (n-1)))cout << "-1\n";
        else
        {
            string s;
            for(i=0;i<n;i++)s+='0';
            --k;
            for(j=0;j<min(60,n-1);j++)
            {
                if((k >> j) & 1)s[n-j-2]='1';
            }
            cur=sz=1;
            vector<int>ans;
            for(i=0;i<n;i++)
            {
                if(s[i] == '0')
                {
                    for(j=cur+sz-1;j>=cur;j--)ans.emplace_back(j);
                    cur+=sz,sz=1;
                }
                else ++sz;
            }
            for(int it : ans)cout << it << ' ';
            cout << '\n';
        }
    }
    return 0;
}