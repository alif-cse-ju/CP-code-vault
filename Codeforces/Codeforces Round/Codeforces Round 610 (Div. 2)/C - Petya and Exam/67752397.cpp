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
     LL a,b,i,j,m,n,t,x,ans,cnt1,cnt2,ache,drkr,haard,sohoj,cnt_sohoj,cnt_hard;
    cin >> m;
    while(m--)
    {
        cin >> n >> t >> a >> b;
        cnt_sohoj=cnt_hard=0LL;
        V<int>hard(n);
        for(i=0;i<n;i++)
        {
            cin >> hard[i];
            if(hard[i] == 1)++cnt_hard;
            else ++cnt_sohoj;
        }
        V<PLL>tasks;
        for(i=0;i<n;i++)
        {
            cin >> x;
            tasks.PSB({x,hard[i]});
        }
        tasks.PSB({t+1LL,0LL});
        sort(tasks.B,tasks.E);
        ans=cnt1=cnt2=0LL;
        for(i=0;i<=n;i++)
        {
            drkr=cnt1*a+cnt2*b;
            ache=tasks[i].FI-drkr-1;
            if(ache >= 0)
            {
                sohoj=min(cnt_sohoj-cnt1,ache/a);
                ache-=sohoj*a;
                haard=min(cnt_hard-cnt2,ache/b);
                ans=max(ans,cnt1+cnt2+haard+sohoj);
            }
            j=i;
            while(j <= n  &&  tasks[i].FI == tasks[j].FI)
            {
                if(tasks[j].SE == 1)++cnt2;
                else ++cnt1;
                ++j;
            }
            i=j-1;
        }
        cout << ans << '\n';
    }
    return 0;
}