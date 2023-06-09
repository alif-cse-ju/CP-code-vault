#include <iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x;
    cin>>x;
    cout<<(x-1)%9+1<<'\n';
    return 0;