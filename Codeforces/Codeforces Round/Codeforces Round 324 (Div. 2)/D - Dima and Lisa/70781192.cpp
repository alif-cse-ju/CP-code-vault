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
    bool primeCheck(int n)
{
    if(n%2 == 0)return false;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i == 0)return false;
    }
    return true;
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int n;
    cin >> n;
    if(primeCheck(n))
    {
        cout << "1\n" << n;
        return 0;
    }
    if(primeCheck(n-2))
    {
        cout << "2\n2 " << n-2;
        return 0;
    }
    if(primeCheck(n-4))
    {
        cout << "3\n2 2 " << n-4;
        return 0;
    }
    for(int i=3;2*i+3 <= n;i+=2)
    {
        if(primeCheck(i)  &&  primeCheck(n-i-3))
        {
            cout << "3\n3 " << i << ' ' << n-i-3;
            return 0;
        }
    }
    return 0;
}