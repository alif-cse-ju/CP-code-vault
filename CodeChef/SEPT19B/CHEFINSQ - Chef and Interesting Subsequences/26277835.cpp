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
LL find_ncr(int n, int k)
{
    LL res = 1;
    if ( k > n - k )
        k = n - k;
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
int main()
{
    FAST();
    //    freopen("input.txt","r",stdin);
    //    freopen("input.txt","w",stdout);
    int i,j,n,k,t,a[53],mn,sum,last,last_cnt,pos;
    LL cnt;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1; i<=n; i++)
        {
            cin >> a[i];
        }
        cnt=0;
        mn=INT_MAX;
        for(i=1; i<=n-k+1; i++)
        {
            sum=a[i];
            if(k > 1)
            {
                PQ<int,V<int>,greater<int> >pq;
                for(j=i+1; j<=n; j++)
                {
                    pq.PS(a[j]);
                }
                j=k-1;
                last=-1;
                while(j--)
                {
                    if(pq.T != last)
                    {
                        last_cnt=1;
                    }
                    else
                    {
                        last_cnt++;
                    }
                    last=pq.T;
                    sum+=last;
                    pq.PP;
                }
                if(sum <= mn)
                {
                    if(sum < mn)
                    {
                        mn=sum;
                        cnt=0;
                    }
                    pos=last_cnt;
                    while(!pq.EM)
                    {
                        if(last == pq.T)
                        {
                            ++last_cnt;
                        }
                        else
                        {
                            break;
                        }
                        pq.PP;
                    }
                    cnt+=find_ncr(last_cnt,pos);
                }
            }
            else
            {
                if(sum < mn)
                {
                    mn=sum;
                    cnt=1;
                }
                else if(sum == mn)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}