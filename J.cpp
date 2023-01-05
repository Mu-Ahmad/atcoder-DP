
#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sp(x) fixed<<setprecision(x)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

double dp[301][301][301];


double fun(int& n, int x, int y, int z)
{
    //Base case
    if(x==0 && y==0 && z==0)
    return 0;
    if(x<0 || y<0 || z<0)
    return 0;

    //Lookup
    if(dp[x][y][z] > -0.9)
    return dp[x][y][z];

    //Rec case
    double ans = fun(n,x-1,y,z) + fun(n,x+1,y-1,z) + fun(n,x,y+1,z-1);

    cout << ans <<<<  n << ' ' << x+y+z << " : ";
    cout <<  (double)n/(x+y+z) << '\n';
    return dp[x][y][z] = ans + (double)n / x+y+z;
}

void stale_flippant() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #define deb(x) cout << #x <<" "; _print(x); cout << endl;
#else
    #define deb(x)
#endif
}


int main()
{
    stale_flippant();
    
    memset(dp,-1,sizeof(dp));
    int n,j;
    cin>>n;

    int o=0,tw=0,th=0;

    for(int i=0;i<n;i++)
    {
        cin>>j;
        if(j == 1)
        o++;
        else if(j == 2)
        tw++;
        else
        th++;
    }

    cout<<sp(10)<<fun(n,o,tw,th)<<endl;

    return 0;
}