#pragma GCC optimize("Ofast")

#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>
#include <climits>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

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

const int M=2e4+5;
const int N=1e6+5;
const int mod=1e9+7;

vector<int>SortCyclicShifts(string const& s)
{
    int i,n=s.size();
    const int alphabet=256;
    vector<int>p(n),c(n),cnt(max(alphabet,n),0);
    for(i=0;i<n;i++)++cnt[s[i]];
    for(i=1;i<alphabet;i++)cnt[i]+=cnt[i-1];
    for(i=1;i<n;i++)p[--cnt[s[i]]]=i;
    c[p[0]]=0;
    int classes=1;
    for(i=1;i<n;i++)
    {
        if(s[p[i]] != s[p[i-1]])++classes;
        c[p[i]]=classes-1;
    }
    vector<int>pn(n),cn(n);
    pair<int,int>cur,prev;
    for(int h=0;(1 << h)<n;h++)
    {
        for(i=0;i<n;i++)
        {
            pn[i]=p[i]-(1 << h);
            if(pn[i] < 0)pn[i]+=n;
        }
        fill(cnt.begin(),cnt.begin()+classes,0);
        for(i=0;i<n;i++)++cnt[c[pn[i]]];
        for(i=1;i<classes;i++)cnt[i]+=cnt[i-1];
        for(i=n-1;i>=0;i--)p[--cnt[c[pn[i]]]]=pn[i];
        cn[p[0]]=0;
        classes=1;
        for(i=1;i<n;i++)
        {
            cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int>SuffixArrayConstruction(string s)
{
    s+="$";
    vector<int>sortedShifts=SortCyclicShifts(s);
    sortedShifts.erase(sortedShifts.begin());
    return sortedShifts;
}

int _rank[M];

vector<int>ConstructLCP(string const& s1,vector<int> const& suffixArray)
{
    string s=s1;
    int i,j,k=0,l=s.size();
    for(i=0;i<l;i++)_rank[suffixArray[i]]=i;
    vector<int>lcp(l-1,0);
    for(i=0;i<l;i++)
    {
        if(_rank[i] == l-1)
        {
            k=0;
            continue;
        }
        j=suffixArray[_rank[i]+1];
        while(i+k < l  &&  j+k < l  &&  s[i+k] == s[j+k])++k;
        lcp[_rank[i]]=k;
        if(k)--k;
    }
    return lcp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;cin >> a >> b;
    string s=a+"A"+b;
    vector<int>suffixArray=SuffixArrayConstruction(s);
    vector<int>lcpArray=ConstructLCP(s,suffixArray);
    int ans=INT_MAX, l=(int)lcpArray.size();
    for(int i=1;i<l;i++)
    {
        if(suffixArray[i] <= (int)a.size()  &&  suffixArray[i+1] <= (int)a.size())continue;
        if(suffixArray[i] > (int)a.size()  &&  suffixArray[i+1] > (int)a.size())continue;
        if(lcpArray[i])
        {
            int v=0;
            if(i+1 < l)v=lcpArray[i+1];
            if(lcpArray[i] > lcpArray[i-1]  &&  lcpArray[i] > v)ans=min(ans, max(lcpArray[i-1],v)+1);
        }
    }
    if(ans == INT_MAX)ans=-1;
    cout << ans;
    return 0;
}
