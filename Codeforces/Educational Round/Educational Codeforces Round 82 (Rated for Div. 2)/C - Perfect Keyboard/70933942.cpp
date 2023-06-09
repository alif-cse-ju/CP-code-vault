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
    string ans;
V<int>adj[30];
bool visited[30];
 void run_dfs(int x)
{
    if(visited[x])return;
    visited[x]=true;
    ans+=(char)('a'+x);
    for(int y : adj[x])run_dfs(y);
}
 int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,l,t,x,y;
    bool valid;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l=s.SZ;
        for(i=0;i<26;i++)visited[i]=false,adj[i].C;
        valid=true;
        for(i=1;i<l;i++)
        {
            x=s[i-1]-'a';
            y=s[i]-'a';
            if(adj[x].EM)adj[x].PSB(y);
            else if(adj[x].SZ == 1  &&  adj[x][0] != y)adj[x].PSB(y);
            else if(adj[x].SZ == 2  &&  adj[x][0] != y  &&  adj[x][1] != y){valid=false;break;}
            if(adj[y].EM)adj[y].PSB(x);
            else if(adj[y].SZ == 1  &&  adj[y][0] != x)adj[y].PSB(x);
            else if(adj[y].SZ == 2  &&  adj[y][0] != x  &&  adj[y][1] != x){valid=false;break;}
        }
        if(!valid)cout << "NO\n";
        else
        {
            ans.C;
            for(i=0;i<26;i++)
            {
                if(!visited[i])
                {
                    if(adj[i].EM)ans+=(char)('a'+i);
                    else if(adj[i].SZ == 1)run_dfs(i);
                }
            }
            if(ans.SZ == 26)cout << "YES\n" << ans << '\n';
            else cout << "NO\n";
        }
    }
    return 0;
}