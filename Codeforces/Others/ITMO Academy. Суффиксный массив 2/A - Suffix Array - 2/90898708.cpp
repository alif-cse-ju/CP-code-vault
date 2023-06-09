#include<bits/stdc++.h>
using namespace std;
vector<int>SortCyclicShifts(string const& s)
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
    //sortedShifts.erase(sortedShifts.begin());
    return sortedShifts;
}
 int main()
{
    string s;
    cin >> s;
    vector<int>ans=SuffixArrayConstruction(s);
    for(int x : ans)cout << x << ' ';
    return 0;
}