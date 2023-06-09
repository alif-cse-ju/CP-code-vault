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
      int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n;
    cin >> n;
    int ans[n+2];
    bool mark[n+2]={0};
    V<int>debe,pabe;
    for(i=1;i<=n;i++)
    {
        cin >> ans[i];
        if(ans[i] == 0)debe.PSB(i);
        else mark[ans[i]]=true;
    }
    for(i=1;i<=n;i++)
    {
        if(!mark[i])pabe.PSB(i);
    }
    for(i=0;i+1<debe.SZ;i+=2)ans[debe[i]]=pabe[i+1],ans[debe[i+1]]=pabe[i];
    if((int)debe.SZ & 1)ans[debe.back()]=pabe.back();
    V<int>temp;
    for(i=1;i<=n;i++)
    {
        if(ans[i] == i)temp.PSB(i);
    }
    for(i=0;i+1<temp.SZ;i+=2)ans[temp[i]]=temp[i+1],ans[temp[i+1]]=temp[i];
    if((int)temp.SZ & 1)
    {
        if(debe[0] != temp.back())swap(ans[debe[0]],ans[temp.back()]);
        else swap(ans[debe[1]],ans[temp.back()]);
    }
    for(i=1;i<=n;i++)cout << ans[i] << ' ';
    return 0;
}