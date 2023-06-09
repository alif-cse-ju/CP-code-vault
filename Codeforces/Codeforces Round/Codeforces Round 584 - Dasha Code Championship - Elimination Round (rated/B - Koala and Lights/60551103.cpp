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
    PII a[102];
int cnt[1002];
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("input.txt","w",stdout);
     int i,n,ans=1;
    string s;
    cin >> n >> s;
    for(i=0; i<n; i++)
    {
        cin >> a[i].FI;
        cin >> a[i].SE;
    }
    int j,x;
    for(i=0; i<n; i++)
    {
        if(s[i] == '0')
        {
            j=a[i].SE;
            for(; j<1001; j+=2*a[i].FI)
            {
                for(int k=j; k<j+a[i].FI  &&  k<1001; k++)
                {
                    cnt[k]++;
                    //cout << i << ' ' << k << endl;
                }
            }
        }
        else
        {
            for(j=0; j<a[i].SE; j++)
            {
                cnt[j]++;
            }
            j=a[i].SE+a[i].FI;
            for(; j<1001; j+=2*a[i].FI)
            {
                for(int k=j; k<j+a[i].FI  &&  k<1001; k++)
                {
                    cnt[k]++;
                    //cout << i << ' ' << k << endl;
                }
            }
        }
    }
    for(i=0; i<=1000; i++)
    {
        ans=max(ans,cnt[i]);
    }
    cout << ans;
    return 0;
}