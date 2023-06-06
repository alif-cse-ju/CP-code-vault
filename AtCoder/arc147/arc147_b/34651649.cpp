#include <bits/stdc++.h>
using namespace std;
int p[405];
vector<pair<char,int>> ans;
void f(char c,int i){
    ans.emplace_back(c,i+1);
    swap(p[i],p[i+1+c-'A']);
}
int main(){
    int N; cin >> N;
    for(int i=0;i<N;i++) cin >> p[i];
    for(int i=0;i<N;i++) for(int j=0;j<N-2;j++) if(p[j]%2!=p[j+2]%2 && p[j]%2!=j%2) f('B',j);
    for(int i=0;i<N-1;i++)if(p[i]%2!=p[i+1] && p[i]%2==i%2) f('A',i);
    for(int i=0;i<N;i++) for(int j=0;j<N-2;j++) if(p[j]>p[j+2]) f('B',j);
    cout << ans.size() << endl;
    for(auto x:ans) cout << x.first << ' ' << x.second << endl;
}