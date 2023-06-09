#include<bits/stdc++.h>
using namespace std;
#define S scanf
#define P printf
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
#define MP make_pair
#define LL long long int
#define ULL unsigned long long int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<long long int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<long long int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
     //int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
      int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,m;
    string x,y,ans;
    set<string>st;
    set<string>pal;
    MSI mp;
    cin >> n >> m;
    for(i=0;i<n;i++)
    {
        cin >> x;
        y=x;
        reverse(y.B,y.E);
        if(x == y)
        {
            ++mp[x];
            pal.insert(x);
        }
        else
        {
            mp[x]++;
            st.insert(x);
        }
    }
    bool odd=0;
    for(string x : pal)
    {
        if(mp[x] & 1)
        {
            if(!odd)
            {
                n=mp[x];
                odd=true;
                for(i=0;i<n;i++)ans+=x;
            }
            else
            {
                n=mp[x];
                n/=2;
                for(i=0;i<n;i++)ans=x+ans;
                for(i=0;i<n;i++)ans=ans+x;
            }
        }
    }
    for(string x : pal)
    {
        if(!(mp[x] & 1))
        {
            n=mp[x];
            n/=2;
            for(i=0;i<n;i++)ans=x+ans;
            for(i=0;i<n;i++)ans=ans+x;
        }
    }
    for(string x : st)
    {
        y=x;
        reverse(y.B,y.E);
        n=min(mp[x],mp[y]);
        for(i=0;i<n;i++)ans=x+ans;
        for(i=0;i<n;i++)ans=ans+y;
        mp[x]=mp[y]=0;
    }
    cout << ans.SZ << '\n' << ans;
    return 0;
}