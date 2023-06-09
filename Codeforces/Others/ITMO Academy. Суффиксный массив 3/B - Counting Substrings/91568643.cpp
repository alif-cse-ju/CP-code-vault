#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
/********************Suffix Array Construction********************/
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
    sortedShifts.erase(sortedShifts.begin());
    return sortedShifts;
}
 /********************Suffix Array Construction********************/
 /********************Searching p in s********************/
 int Compare(string const& x,string const& y)
{
    if(x == y)return 0;
    if(x > y)return 1;
    return -1;
}
 pair<int,int>FindString(string const& s,string const& p,vector<int>const& suffixArray)
{
    string temp;
    int l=0,r=-1,sz=suffixArray.size();
    int check,low,mid,high,ls=s.size(),lp=p.size();
    low=0,high=sz-1;
    while(low <= high)
    {
        mid=(low+high) >> 1;
        temp=s.substr(suffixArray[mid],min(lp,ls-suffixArray[mid]));
        check=Compare(temp,p);
        if(!check)
        {
            l=mid;
            high=mid-1;
        }
        else if(check > 0)high=mid-1;
        else low=mid+1;
    }
    low=0,high=sz-1;
    while(low <= high)
    {
        mid=(low+high) >> 1;
        temp=s.substr(suffixArray[mid],min(lp,ls-suffixArray[mid]));
        check=Compare(temp,p);
        if(!check)
        {
            r=mid;
            low=mid+1;
        }
        else if(check > 0)high=mid-1;
        else low=mid+1;
    }
    return {l,r};
}
 /********************Searching p in s********************/
 int main()
{
    int n;
    string s,p;
    pair<int,int>ans;
    cin >> s;
    vector<int>suffixArray=SuffixArrayConstruction(s);
    cin >> n;
    while(n--)
    {
        cin >> p;
        ans=FindString(s,p,suffixArray);
        cout << ans.second-ans.first+1 << '\n';
    }
    return 0;
}