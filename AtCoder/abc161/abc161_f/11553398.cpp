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




bool check(LL n,LL k)
{
    if(n < k)return 0;
    while(n >= k)
    {
        if(n%k == 0)n/=k;
        else n-=n/k*k;
    }
    return n == 1LL;
}

int main()
{
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    LL i,n,rt,cnt=2;
    cin >> n;
    if(n == 2)cout << "1";
    else
    {
        rt=sqrt(n);
        for(i=2;i<=rt;i++)
        {
            cnt+=check(n,i);
            if(n/i != i)cnt+=check(n,n/i);
        }
        cout << cnt;
    }
    return 0;
}
