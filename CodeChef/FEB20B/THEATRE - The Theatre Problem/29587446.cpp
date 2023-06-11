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
#define PSB emplace_back
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
int ara1[6],ara2[6],cost[6],cnt[6][6];
int main()
{
    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    V<int>v;
    string s;
    int i,j,n,t,x,ans=0,temp;
    cost[1]=25,cost[2]=50,cost[3]=75,cost[4]=100;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<5;i++)
        {
            ara1[i]=ara2[i]=i;
            for(j=1;j<=i;j++)cnt[i][j]=cnt[j][i]=0;
        }
        while(n--)
        {
            cin >> s >> x;
            ++cnt[s[0]-'A'+1][x/3];
        }
        ans=INT_MIN;
        do
        {
            do
            {
                temp=0;
                for(i=1;i<5;i++)
                {
                    if(cnt[i][ara1[i]] == 0)temp-=100;
                    else temp+=cnt[i][ara1[i]]*cost[ara2[i]];
                }
                ans=max(ans,temp);
            }
            while(next_permutation(ara2+1,ara2+5));
        }
        while(next_permutation(ara1+1,ara1+5));
        cout << ans << '\n';
        v.PSB(ans);
    }
    ans=0;
    for(int y : v)ans+=y;
    cout << ans << '\n';
    return 0;
}