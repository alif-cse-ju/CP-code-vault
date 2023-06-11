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
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int N=1e5;
int l,cnt[10][N+2];
bool Check(int k)
{
    int i,j,odd,check;
    for(i=k;i<=l;i++)
    {
        odd=0;
        for(j=0;j<10;j++)
        {
            check=cnt[j][i]-cnt[j][i-k];
            if(check & 1)++odd;
        }
        if(!odd)return 1;
        if((k & 1)  &&  odd == 1)return 1;
    }
    return 0;
}
int main()
{
    FAST();
    char s[N+2];
    int i,j,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> s+1;
        l=strlen(s+1);
        for(i=1;i<=l;i++)
        {
            for(j=0;j<10;j++)cnt[j][i]=cnt[j][i-1];
            ++cnt[s[i]-'0'][i];
        }
        ans=1;
        for(i=l;i>1;i--)
        {
            if(Check(i))
            {
                ans=i;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}