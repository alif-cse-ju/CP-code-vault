#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e5+5;
const int mod=1e9+7;
int main()
    FAST();
    bool flag;
    string s,ans;
    int i,l,t,mn,idx;
    cin >> t;
    while(t--)
    {
        ans="";
        cin >> s;
        l=(int)s.size();
        deque<int>pos[26];
        for(i=0;i<l;i++)pos[s[i]-'a'].emplace_back(i);
        while(true)
        {
            flag=0;
            for(i=0;i<26  &&  !flag;i++)
            {
                if(!pos[i].empty())flag=1;
            }
            if(!flag)break;
            mn=INT_MAX;
            for(i=0;i<26;i++)
            {
                if(!pos[i].empty())
                {
                    if(pos[i].back() < mn)
                    {
                        idx=i;
                        mn=pos[i].back();
                    }
                }
            }
            for(i=idx+1;i<26;i++)
            {
                if(!pos[i].empty()  &&  pos[i].front() < mn)idx=i;
            }
            ans+=(char)(idx+'a');
            for(i=0;i<26;i++)
            {
                if(i == idx)continue;
                while(!pos[i].empty()  &&  pos[i].front() < pos[idx].front())pos[i].pop_front();
            }
            while(!pos[idx].empty())pos[idx].pop_front();
        }
        cout << ans << '\n';
    }
    return 0;
}