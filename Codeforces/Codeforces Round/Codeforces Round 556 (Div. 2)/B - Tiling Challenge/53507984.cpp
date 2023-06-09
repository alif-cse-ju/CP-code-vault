#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define PB push_back
#define LL long long int
#define PII pair<int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MLI map<long long int,int>
string grid[55];
void check_grid(int i,int j)
    if(grid[i-1][j] == '.' && grid[i+1][j] == '.' && grid[i][j-1] == '.' && grid[i][j+1] == '.')
    {
        grid[i][j]='#';
        grid[i-1][j]='#';
        grid[i+1][j]='#';
        grid[i][j-1]='#';
        grid[i][j+1]='#';
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,j,n;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> grid[i];
    }
    for(i=1;i<n-1;i++)
    {
        for(j=1;j<n-1;j++)
        {
            if(grid[i][j] == '.')
            {
                check_grid(i,j);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(grid[i][j] == '.')
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}