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



ULL m,n,arr[100002];

ULL gcd(ULL a, ULL b)
{
    if (b == 0LL)return a;
    return gcd(b, a % b);
}

ULL findlcm()
{
    ULL ans = arr[0];
    for (int i = 1; i < n; i++)ans = (((arr[i] * ans)) /(gcd(arr[i], ans)));
    return ans;
}

int main()
{
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i;
    cin >> n >> m;
    for(i=0;i<n;i++)cin >> arr[i],arr[i]/=2ULL;
    ULL lcm=findlcm();
    for(i=0;i<n;i++)
    {
        if((lcm/arr[i])%2ULL == 0)
        {
            cout << "0";
            return 0;
        }
    }
    ULL ans=m/lcm;
    ans=(ans/2ULL)+(ans%2ULL);
    cout << ans;
    return 0;
}
