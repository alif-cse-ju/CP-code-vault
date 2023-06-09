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
#define FAST() ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
     int ans_cnt[1002][28];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,m,n;
    string s;
    cin >> n >> m;
    int points[m+2];
    for(i=0; i<n; i++)
    {
        cin >> s;
        for(j=0; j<m; j++)
        {
            ans_cnt[j+1][s[j]-'A'+1]++;
        }
    }
    for(i=1; i<=m; i++)
    {
        cin >> points[i];
    }
    int ans=0,mx;
    for(i=1; i<=m; i++)
    {
        mx=-1;
        for(j=1; j<27; j++)
        {
            mx=max(mx,ans_cnt[i][j]);
        }
        ans+=(mx*points[i]);
    }
    cout << ans;
    return 0;
}