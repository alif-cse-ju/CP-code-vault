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
     int i,l,t,x,y,cnt;
    string s;
    char c;
    pair<char,PII>x1,y1,z1,x2,y2;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l=s.SZ;
        Q<pair<char,PII> >q;
        c=s[0],x=0;
        for(i=1;i<l;i++)
        {
            if(s[i] != c)
            {
                q.PS({c,{x,i-1}});
                c=s[i],x=i;
            }
        }
        q.PS({c,{x,i-1}});
        V<PII>ans;
        while(!q.EM)
        {
            x1=q.F,q.PP;
            if(x1.FI == 't')
            {
                if(!q.EM  &&  q.F.FI == 'w')
                {
                    y1=q.F,q.PP;
                    if(y1.SE.SE-y1.SE.FI == 0  &&  !q.EM  &&  q.F.FI == 'o')
                    {
                        z1=q.F,q.PP;
                        if(!q.EM  &&  q.F.FI == 'n')
                        {
                            x2=q.F,q.PP;
                            if(x2.SE.SE-x2.SE.FI == 0  &&  !q.EM  &&  q.F.FI == 'e')
                            {
                                y2=q.F,q.PP;
                                if(z1.SE.SE-z1.SE.FI == 0)ans.PSB(z1.SE);
                                else
                                {
                                    ans.PSB(y1.SE);
                                    ans.PSB(x2.SE);
                                }
                            }
                            else ans.PSB(y1.SE);
                        }
                        else ans.PSB(y1.SE);
                    }
                }
            }
            else if(x1.FI == 'o')
            {
                if(!q.EM  &&  q.F.FI == 'n')
                {
                    y1=q.F,q.PP;
                    if(y1.SE.SE-y1.SE.FI == 0  &&  !q.EM  &&  q.F.FI == 'e')
                    {
                        z1=q.F,q.PP;
                        ans.PSB(y1.SE);
                    }
                }
            }
        }
        cout << ans.SZ << '\n';
        for(PII temp : ans)cout << temp.FI+1 << ' ';
        cout << '\n';
    }
    return 0;
}