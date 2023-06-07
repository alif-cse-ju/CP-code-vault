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
const int N=1e6+5;
const int mod=998244353;
struct Node
    int minVal,bit[2];
    Node()
    {
        minVal=N;
        bit[0]=bit[1]=-1;
    }
int curNode[M];
bool visited[M];
Node temp=Node();
vector<int>divisors[M];
vector<Node>trieTree[M];
void PreCal()
{
    int i,j;
    for(i=1;i<M;i++)
    {
        trieTree[i].emplace_back(temp);
        for(j=i;j<M;j+=i)divisors[j].emplace_back(i);
    }
}
 void Update(int idx,int val)
{
    int i,cur=0;
    trieTree[idx][cur].minVal=min(val,trieTree[idx][cur].minVal);
    for(i=18;i>=0;i--)
    {
        if(trieTree[idx][cur].bit[(val >> i) & 1] == -1)trieTree[idx][cur].bit[(val >> i) & 1]=++curNode[idx], trieTree[idx].emplace_back(temp);
        cur=trieTree[idx][cur].bit[(val >> i) & 1];
        trieTree[idx][cur].minVal=min(val,trieTree[idx][cur].minVal);
    }
}
 int Query(int x,const int& k,const int& s)
{
    int ans=0,b,i,cur=0;
    if(x%k  ||  trieTree[k][cur].minVal+x > s)return -1;
    for(i=18;i>=0;i--)
    {
        b=((x >> i) & 1);
        if(trieTree[k][cur].bit[b ^ 1] != -1  &&  trieTree[k][trieTree[k][cur].bit[b ^ 1]].minVal+x <= s)ans += ((b ^ 1) << i), cur=trieTree[k][cur].bit[b ^ 1];
        else ans += (b << i), cur=trieTree[k][cur].bit[b];
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,s,t,q,x;
    PreCal();
    cin >> q;
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> x;
            if(visited[x])continue;
            visited[x]=1;
            for(int d : divisors[x])Update(d,x);
        }
        else
        {
            cin >> x >> k >> s;
            cout << Query(x,k,s) << '\n';
        }
    }
    return 0;
}