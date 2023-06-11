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
int main()
{
    FAST();
    string s;
    int i,t,x,ans,cnt[26],one,two;
    cin >> t;
    while(t--)
    {
        cin >> s;
        memset(cnt,0,sizeof(cnt));
        for(char c : s)++cnt[c-'a'];
        ans=one=0;
        for(i=0;i<26;i++)
        {
            if(cnt[i] == 1)++one,cnt[i]=0;
        }
        for(i=0;i<26  &&  one;)
        {
            if(cnt[i] == 1)++one,cnt[i]=0;
            if(cnt[i] > 1)
            {
                cnt[i]-=2;
                ++ans;
                --one;
            }
            else i++;
        }
        two=0;
        for(i=0;i<26;i++)
        {
            if((cnt[i] & 1)  &&  cnt[i] > 2)
            {
                ++ans;
                cnt[i]-=3;
            }
            two+=cnt[i]/2;
        }
        ans+=(two/3)*2;
        if(two%3 > 1)++ans;
        cout << ans << '\n';
    }
    return 0;
}