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
int k,n,arr[200005],pos[200005];
void FindAns()
{
    set<PII>bal;
    int a,b,c,d,i,l;
    V<pair<int,PII> >ans;
    for(i=1;i<=n;i++)
    {
        if(arr[i] == i)continue;
        if(arr[i] == pos[i])bal.insert({min(i,pos[i]),max(i,pos[i])});
        else
        {
            a=i;
            b=arr[i];
            c=pos[i];
            arr[c]=arr[b],arr[b]=b;
            pos[b]=b,pos[arr[c]]=c;
            ans.PSB({a,{b,c}});
        }
    }
    l=bal.SZ;
    if(l & 1)
    {
        cout << "-1\n";
        return;
    }
    V<PII>pore(bal.B,bal.E);
    for(i=0;i<l;i+=2)
    {
        a=pore[i].FI,b=pore[i].SE;
        c=pore[i+1].FI,d=pore[i+1].SE;
        ans.PSB({b,{a,c}}),ans.PSB({c,{b,d}});
    }
    l=ans.SZ;
    if(l > k)
    {
        cout << "-1\n";
        return;
    }
    cout << l << '\n';
    for(pair<int,PII> x : ans)cout << x.FI << ' ' << x.SE.FI << ' ' << x.SE.SE << '\n';
}
int main()
{
    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)cin >> arr[i],pos[arr[i]]=i;
        FindAns();
    }
    return 0;
}