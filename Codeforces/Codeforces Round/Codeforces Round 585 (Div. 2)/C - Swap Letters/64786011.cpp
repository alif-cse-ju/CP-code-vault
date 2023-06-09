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
      int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     string a,b;
    V<PII>ans;
    V<int>ab,ba;
    int i,n,cnt[2]={0};
    cin >> n >> a >> b;
    for(i=0;i<n;i++)
    {
        ++cnt[a[i]-'a'];
        ++cnt[b[i]-'a'];
        if(a[i] != b[i])
        {
            if(a[i] == 'a')ab.PSB(i);
            else ba.PSB(i);
        }
    }
    if((cnt[0] & 1)  ||  (cnt[1] & 1))
    {
        cout << "-1";
        return 0;
    }
    for(i=1;i<ab.SZ;i+=2)
    {
        swap(b[ab[i-1]],a[ab[i]]);
        ans.PSB({ab[i],ab[i-1]});
    }
    for(i=1;i<ba.SZ;i+=2)
    {
        swap(a[ba[i-1]],b[ba[i]]);
        ans.PSB({ba[i-1],ba[i]});
    }
    if(((int)ab.SZ) & 1)
    {
        ans.PSB({ba[ba.SZ-1],ba[ba.SZ-1]});
        ans.PSB({ba[ba.SZ-1],ab[ab.SZ-1]});
    }
    cout << ans.SZ << '\n';
    for(PII x : ans)cout << x.FI+1 << ' ' << x.SE+1 << '\n';
    return 0;
}