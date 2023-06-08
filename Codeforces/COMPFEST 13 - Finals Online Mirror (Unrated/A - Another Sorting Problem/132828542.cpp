#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
struct Data{
    int idx, nxt[26];
node[N];
int cnt;
void Insert(const string& s,const int& id)
    int cur=0,i,l=(int)s.size();
    for(i=0;i<l;i++)
    {
        if(node[cur].nxt[s[i]-'A'])cur=node[cur].nxt[s[i]-'A'];
        else cur=node[cur].nxt[s[i]-'A']=++cnt;
    }
    node[cur].idx=id;
 void Traverse(int nodeNum,int len)
{
    if(node[nodeNum].idx)
    {
        cout << node[nodeNum].idx << ' ';
        return;
    }
    int i;
    if(len & 1)
    {
        for(i=0;i<26;i++)
        {
            if(node[nodeNum].nxt[i])Traverse(node[nodeNum].nxt[i],len+1);
        }
    }
    else
    {
        for(i=25;i>=0;i--)
        {
            if(node[nodeNum].nxt[i])Traverse(node[nodeNum].nxt[i],len+1);
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,m,n;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> s, Insert(s,i);
    Traverse(0,1);
    return 0;
}