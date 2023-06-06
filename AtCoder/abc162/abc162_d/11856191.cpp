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




int cntB[4005];
int cntG[4005];
int cntR[4005];

int main()
{
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,n;
    LL ans=0;
    char s[4005];
    cin >> n >> s+1;
    for(i=n;i>0;i--)
    {
        cntB[i]=cntB[i+1]+(s[i] == 'B');
        cntG[i]=cntG[i+1]+(s[i] == 'G');
        cntR[i]=cntR[i+1]+(s[i] == 'R');
    }
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(s[i] != s[j])
            {
                if((s[i] == 'B'  &&  s[j] == 'G')  ||  (s[i] == 'G'  &&  s[j] == 'B'))ans+=cntR[j];
                else if((s[i] == 'B'  &&  s[j] == 'R')  ||  (s[i] == 'R'  &&  s[j] == 'B'))ans+=cntG[j];
                else ans+=cntB[j];
                if(j+(j-i) <= n  &&  s[j+(j-i)] != s[i]  &&  s[j+(j-i)] != s[j])--ans;
            }
        }
    }
    cout << ans;
    return 0;
}
