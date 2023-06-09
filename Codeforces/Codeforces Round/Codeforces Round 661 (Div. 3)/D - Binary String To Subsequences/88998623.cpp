#include<bits/stdc++.h>
using namespace std;
#define G getline
#define SZ size()
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define EM empty()
#define V vector
#define Q queue
#define DQ deque
#define PQ priority_queue
#define ST stack
#define FI first
#define SE second
#define PI acos(-1)
#define PS push
#define PP pop()
#define PSF push_front
#define PSB push_back
#define PPF pop_front()
#define PPB pop_back()
#define LL long long
#define ULL unsigned long long
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<LL,int>
#define PLL pair<LL,LL>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<LL,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    //int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
      int main()
{
    FAST();
    bool tgl;
    char s[200005];
    int i,l,t,x,y,cnt,ans[200005];
    cin >> t;
    while(t--)
    {
        cin >> l >> s+1;
        set<int>st0,st1;
        for(i=1;i<=l;i++)
        {
            if(s[i] == '0')st0.insert(i);
            else st1.insert(i);
        }
        cnt=0;
        while(!st0.empty()  &&  !st1.empty())
        {
            ++cnt;
            x=*(st0.begin());
            y=*(st1.begin());
            if(x < y)tgl=1,st0.erase(x);
            else tgl=0,x=y,st1.erase(x);
            ans[x]=cnt;
            while(true)
            {
                if(tgl)
                {
                    auto it=st1.lower_bound(x);
                    if(it == st1.end())break;
                    x=*(it),ans[x]=cnt;
                    st1.erase(x);
                }
                else
                {
                    auto it=st0.lower_bound(x);
                    if(it == st0.end())break;
                    x=*(it),ans[x]=cnt;
                    st0.erase(x);
                }
                tgl=!tgl;
            }
        }
        while(!st0.empty())
        {
            auto it=st0.begin();
            x=*(it),ans[x]=++cnt;
            st0.erase(x);
        }
        while(!st1.empty())
        {
            auto it=st1.begin();
            x=*(it),ans[x]=++cnt;
            st1.erase(x);
        }
        cout << cnt << '\n';
        for(i=1;i<=l;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}