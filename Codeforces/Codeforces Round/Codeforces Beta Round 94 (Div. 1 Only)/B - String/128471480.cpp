#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000000LL
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define getbit(n,i) (((n)&(1LL<<(i)))!=0)
#define setbit0(n,i) ((n)&(~(1LL<<(i))))
#define setbit1(n,i) ((n)|(1LL<<(i)))
#define lastone(n) ((n)&(-(n)))
#define read freopen("debug//in.txt","r",stdin)
#define write freopen("debug//out.txt","w",stdout)
#define DBG(a) cerr<<#a<<" ->->->-> "<<a<<"\n"
#define fi first
#define se second
#define PI (acos(-1))
#define fastread ios::sync_with_stdio(false);cin.tie(NULL)
#define mod (1000000007)
#define asz 1000005
template<class T,class V> ostream& operator<<(ostream &s,pair<T,V> a)
    s<<a.fi<<' '<<a.se;
    return s;
struct vertex{
    int link,len;
    ll cnt,d;
    map<char,int> next;
    vertex(){
        link=-1,len=0,cnt=0;
    }
vertex sa[asz*2];
int last=0,sz=1;
void add_char(char c){
    int cur=sz++;
    sa[cur].len=sa[last].len+1;
    sa[cur].cnt=1;
    int u=last;
    while(u!=-1&&sa[u].next.count(c)==0){
        sa[u].next[c]=cur;
        u=sa[u].link;
    }
    if(u==-1)
        sa[cur].link=0;
    else{
        int v=sa[u].next[c];
        if(sa[u].len==sa[v].len-1)
            sa[cur].link=v;
        else{
            int nw=sz++;
            sa[nw].link=sa[v].link;
            sa[nw].len=sa[u].len+1;
            sa[nw].next=sa[v].next;
            sa[nw].cnt=0;
            while(u!=-1&&sa[u].next[c]==v){
                sa[u].next[c]=nw;
                u=sa[u].link;
            }
            sa[v].link=sa[cur].link=nw;
        }
    }
    last=cur;
}
void pre(){
    vector<vector<int>> v(sz+1);
    for(int i=0;i<sz;i++)v[sa[i].len].push_back(i);
    for(int i=sz;i>=0;i--)for(auto x:v[i])if(x)sa[sa[x].link].cnt+=sa[x].cnt;
    sa[0].cnt=0;
    for(int i=sz;i>=0;i--){
        for(auto x:v[i]){
            sa[x].d=sa[x].cnt;
            for(auto u:sa[x].next)sa[x].d+=sa[u.se].d;
        }
    }
}
int main()
{
    fastread;
#ifdef FILE_IO
    read;
    write;
#endif
    int T=1;
//    cin>>T;
    for(int qq=1; qq<=T; qq++)
    {
        string s;
        cin>>s;
        int k;
        cin>>k;
        for(auto x:s)add_char(x);
        pre();
        if(sa[0].d<k){
            cout<<"No such line."<<endl;
            continue;
        }
        string ans;
        int v=0;
        while(k>sa[v].cnt){
            k-=sa[v].cnt;
            for(auto x:sa[v].next){
                if(k<=sa[x.se].d){
                    ans.push_back(x.fi);
                    v=x.se;
                    break;
                }
                k-=sa[x.se].d;
            }
        }
        cout<<ans<<endl;
    }
}