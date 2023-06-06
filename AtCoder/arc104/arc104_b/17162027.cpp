#include<bits/stdc++.h>

using namespace std;

#define G getline
#define C clear()
#define B begin()
#define F front()
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




int cnt[27][5002];

int main()
{
    FAST();
    int i,j,l,x1,x2,y1,y2,ans=0;
    string s;
    cin >> l >> s;
    for(i=1;i<=l;i++)++cnt[s[i-1]-'A'][i];
    for(i=1;i<=l;i++)
    {
        for(j=0;j<26;j++)cnt[j][i]+=cnt[j][i-1];
    }
    for(i=2;i<=l;i++)
    {
        for(j=1;j<i;j++)
        {
            x1=cnt[0][i]-cnt[0][j-1];
            x2=cnt['T'-'A'][i]-cnt['T'-'A'][j-1];
            y1=cnt['C'-'A'][i]-cnt['C'-'A'][j-1];
            y2=cnt['G'-'A'][i]-cnt['G'-'A'][j-1];
            if(x1 == x2  &&  y1 == y2)++ans;
        }
    }
    cout << ans;
    return 0;
}
