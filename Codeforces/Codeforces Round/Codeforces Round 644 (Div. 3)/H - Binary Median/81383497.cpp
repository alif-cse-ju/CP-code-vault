#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,t;
    string s;
    bool flag;
    LL m,n,cur,left,need;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<LL>v(n);
        for(i=0;i<n;i++)
        {
            cin >> s;
            for(char c : s)v[i]*=2,v[i]+=c-'0';
        }
        cur=(1LL << (m-1))-1;
        need=((1LL << m)-n-1)/2+1;
        while(true)
        {
            left=cur+1;
            flag=false;
            for(i=0;i<n;i++)
            {
                flag |= v[i] == cur;
                if(v[i] <= cur)--left;
            }
            if(left == need  &&  !flag)
            {
                s="";
                for(i=0;i<m;i++)
                {
                    s+=(char)('0'+cur%2);
                    cur/=2;
                }
                reverse(s.begin(),s.end());
                cout << s << '\n';
                break;
            }
            else if(left < need)++cur;
            else --cur;
        }
    }
    return 0;
}