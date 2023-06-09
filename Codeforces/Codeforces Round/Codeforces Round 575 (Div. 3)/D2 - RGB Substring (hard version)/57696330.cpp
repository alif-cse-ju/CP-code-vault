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
      int cnt1[200005],cnt2[200005],cnt3[200005];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,q,n,k,ans;
    string s;
    cin >> q;
    while(q--)
    {
        cin >> n >> k;
        cin >> s;
        ans=INT_MAX;
        cnt1[0]=0;
        cnt2[0]=0;
        cnt3[0]=0;
        for(i=0; i<n; i++)
        {
            if(i%3 == 0)
            {
                if(s[i] == 'R')
                {
                    cnt1[i+1]=cnt1[i];
                    cnt2[i+1]=(cnt2[i]+1);
                    cnt3[i+1]=(cnt3[i]+1);
                }
                else if(s[i] == 'G')
                {
                    cnt1[i+1]=(cnt1[i]+1);
                    cnt2[i+1]=cnt2[i];
                    cnt3[i+1]=(cnt3[i]+1);
                }
                else
                {
                    cnt1[i+1]=(cnt1[i]+1);
                    cnt2[i+1]=(cnt2[i]+1);
                    cnt3[i+1]=cnt3[i];
                }
            }
            else if(i%3 == 1)
            {
                if(s[i] == 'G')
                {
                    cnt1[i+1]=cnt1[i];
                    cnt2[i+1]=(cnt2[i]+1);
                    cnt3[i+1]=(cnt3[i]+1);
                }
                else if(s[i] == 'B')
                {
                    cnt1[i+1]=(cnt1[i]+1);
                    cnt2[i+1]=cnt2[i];
                    cnt3[i+1]=(cnt3[i]+1);
                }
                else
                {
                    cnt1[i+1]=(cnt1[i]+1);
                    cnt2[i+1]=(cnt2[i]+1);
                    cnt3[i+1]=cnt3[i];
                }
            }
            else
            {
                if(s[i] == 'B')
                {
                    cnt1[i+1]=cnt1[i];
                    cnt2[i+1]=(cnt2[i]+1);
                    cnt3[i+1]=(cnt3[i]+1);
                }
                else if(s[i] == 'R')
                {
                    cnt1[i+1]=(cnt1[i]+1);
                    cnt2[i+1]=cnt2[i];
                    cnt3[i+1]=(cnt3[i]+1);
                }
                else
                {
                    cnt1[i+1]=(cnt1[i]+1);
                    cnt2[i+1]=(cnt2[i]+1);
                    cnt3[i+1]=cnt3[i];
                }
            }
        }
        for(i=k; i<=n; i++)
        {
            ans=min(ans,min(cnt1[i]-cnt1[i-k],min(cnt2[i]-cnt2[i-k],cnt3[i]-cnt3[i-k])));
        }
        cout << ans << '\n';
    }
    return 0;
}