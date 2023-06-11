#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
int Solve(string s)
{
    int block,i,j,l,single;
    block=single=0, l=(int)s.size();
    for(i=1;i+1<l;i++)
    {
        if(s[i] != s[i-1]   &&  s[i] != s[i+1])++single, s[i]='0'+'1'-s[i];
    }
    for(i=0;i<l;)
    {
        j=i;
        while(j < l  &&  s[i] == s[j])++j;
        i=j, ++block;
    }
    return block+single-(block & 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        cout << min(Solve("0"+s+"0"), Solve("1"+s+"1")) << '\n';
    }
    return 0;
}