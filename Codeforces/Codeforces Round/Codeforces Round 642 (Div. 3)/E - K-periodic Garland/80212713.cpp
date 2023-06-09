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
      auto Solve = [](const string &s)
    {
        int i,l=s.SZ,ans,cnt,cur,pre=0;
        ans=cnt=count(s.B,s.E,'1');
        V<int>res(l);
        for(i=0;i<l;i++)
        {
            cur=(s[i] == '1');
            pre+=cur,res[i]=1-cur;
            if(i > 0)res[i]+=min(res[i-1],pre-cur);
            ans=min(ans,res[i]+cnt-pre);
        }
        return ans;
    };
     string s;
    int i,k,n,t,ans,cnt;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> s;
        V<string>v(k);
        cnt=count(s.B,s.E,'1');
        for(i=0;i<n;i++)v[i%k]+=s[i];
        ans=INT_MAX;
        for(string it : v)ans=min(ans,(int)Solve(it)+(cnt-count(it.B,it.E,'1')));
        cout << ans << '\n';
    }
    return 0;
}