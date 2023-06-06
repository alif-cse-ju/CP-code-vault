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




char s[500005];
int n,cnt[27][500005];

void update(int i,int j,int x)
{
    while(j <= n)
    {
        cnt[i][j]+=x;
        j+=(j & (-j));
    }
}

int getSum(int i,int j)
{
    int sum=0;
    while(j > 0)
    {
        sum+=cnt[i][j];
        j-=(j & (-j));
    }
    return sum;
}

int main()
{
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,q,x,y,ans;
    string s1;
    cin >> n >> s+1;
    for(i=1;i<=n;i++)update(s[i]-'a'+1,i,1);
    cin >> q;
    while(q--)
    {
        cin >> x;
        if(x == 1)
        {
            cin >> x >> s1;
            update(s[x]-'a'+1,x,-1);
            update(s1[0]-'a'+1,x,1);
            s[x]=s1[0];
        }
        else
        {
            ans=0;
            cin >> x >> y;
            for(i=1;i<27;i++)ans+=((getSum(i,y)-getSum(i,x-1)) > 0);
            cout << ans << '\n';
        }
    }
    return 0;
}
