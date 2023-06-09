#include<bits/stdc++.h>
using namespace std;
#define S scanf
#define P printf
#define G getline
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define Em empty()
#define V vector
#define Q queue
#define PQ priority_queue
#define ST stack
#define Fi first
#define Se second
#define Pi acos(-1)
#define PS push
#define PP pop
#define PSB push_back
#define PPB pop_back
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
void FAST();
LL big_mod(LL val,LL pow,LL mod);
    MSI mp;
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,mark=0;
    string s,tm[3];
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> s;
        if(mp[s] == 0)
        {
            tm[++mark]=s;
        }
        mp[s]++;
    }
    if(mp[tm[1]] > mp[tm[2]])
    {
        cout << tm[1];
    }
    else
    {
        cout << tm[2];
    }
    return 0;
}
       void FAST()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 LL big_mod(LL val,LL pow,LL mod)
{
    LL res=1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)
        {
            res = (res*val) % mod;
        }
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
}