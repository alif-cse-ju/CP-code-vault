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




const int N=3005;
string ans;
char s[N],t[N];
int ls,lt,dp[N][N];

void LCS()
{
    int i,j;
    for(i=0;i<=ls;i++)
    {
        for(j=0;j<=lt;j++)
        {
            if(!i  ||  !j)dp[i][j]=0;
            else if(s[i] == t[j])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    i=ls,j=lt;
    while(i  &&  j)
    {
        if(s[i] == t[j])
        {
            ans+=s[i];
            i--,j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])i--;
        else j--;
    }
}

int main()
{
    FAST();
    cin >> s+1 >> t+1;
    ls=strlen(s+1);
    lt=strlen(t+1);
    LCS();
    reverse(ans.begin(),ans.end());
    cout << ans;
    return 0;
}
