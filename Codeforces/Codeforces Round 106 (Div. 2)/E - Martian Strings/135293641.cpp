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
const int M=1e3+5;
const int N=1e6+5;
const int mod=998244353;
int mn[M];
vector<int>PrefixFunction(const string& s)
    int n = (int)s.size();
    vector<int> pi(n);
    for(int i = 1; i < n; i++)
    {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
        j = pi[j-1];
        if (s[i] == s[j])
        j++;
        pi[i] = j;
    }
    return pi;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s1r,s2;
    int ans=0,i,l1,l2,n;
    cin >> s1 >> n;
    l1=(int)s1.size();
    s1r=s1;
    reverse(s1r.begin(),s1r.end());
    while(n--)
    {
        cin >> s2;
        l2=(int)s2.size();
        for(i=1;i<=l2;i++)mn[i]=l1+5;
        vector<int>v1=PrefixFunction(s2+"#"+s1);
        for(i=l2+1;i<=l1+l2;i++)mn[v1[i]]=min(mn[v1[i]],i-l2);
        mn[0]=mn[l2]=l1+5;
        reverse(s2.begin(),s2.end());
        vector<int>v2=PrefixFunction(s2+"#"+s1r);
        for(i=l2+1;i<=l1+l2;i++)
        {
            if(l1-(i-l2)+1 > mn[l2-v2[i]])
            {
                ++ans;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}