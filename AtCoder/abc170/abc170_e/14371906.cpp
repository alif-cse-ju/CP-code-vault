#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int sz,a[200002],pos[200002],tree[1000002];
multiset<int,greater<int> >kindergarten[200002];

void Update(int i,int val)
{
    i+=sz;
    tree[i]=val;
    while(i > 1)
    {
        i/=2;
        tree[i]=min(tree[i << 1],tree[(i << 1)+1]);
    }
}

int main()
{
    FAST();
    int h,i,n,q,x,y,idx;
    h=(int)ceil(log2(200001));
    sz=1 << (h+1);
    cin >> n >> q;
    for(i=1;i<=n;i++)
    {
        cin >> a[i] >> x;
        pos[i]=x;
        kindergarten[x].insert(a[i]);
    }
    fill(tree,tree+1000001,1e9);
    for(i=1;i<=200000;i++)
    {
        if(!kindergarten[i].empty())Update(i,*(kindergarten[i].begin()));
    }
    while(q--)
    {
        cin >> x >> y;
        idx=pos[x],pos[x]=y;
        kindergarten[idx].erase(a[x]);
        kindergarten[y].insert(a[x]);
        if(kindergarten[idx].empty())Update(idx,1e9);
        else Update(idx,*(kindergarten[idx].begin()));
        Update(y,*(kindergarten[y].begin()));
        cout << tree[1] << '\n';
    }
    return 0;
}
