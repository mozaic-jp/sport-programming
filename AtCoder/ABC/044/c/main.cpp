#include <iostream>
#include <fstream>
#include <vector>

#define DEBUG 0

using namespace std;
#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;

//https://atcoder.jp/contests/abc044/tasks/arc060_a

int main(){

#if DEBUG
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int n,a;
    cin >> n >> a;
    vector <int> x(n);

    REP(i,n)
    {
        cin >> x[i];
    }

    //dp[j][k][s]: j枚のうちk枚選んだときの合計がsだったときのの選び方
    ll dp[n+1][n+1][2501];
    REP(j,n+1)
    {
        REP(k,n+1)
        {
            REP(s,n*a + 1)
            {
                dp[j][k][s] = 0;
            }
        }
    }

    dp[0][0][0] = 1;

    for(int j = 1; j <= n; ++j)
    {
        for(int k = 0; k <= n; ++k)
        {
            for(ll s = 0; s <= 2500; ++s)
            {
                if(k == 0 || s - x[j-1] < 0)
                {
                    dp[j][k][s] = dp[j-1][k][s];
                }
                else
                {
                    dp[j][k][s] = dp[j-1][k][s] + dp[j-1][k-1][s-x[j-1]];
                }
            }
        }
    }
    //dp[j][k][s] = dp[j-1][k][s];
    //dp[j][k][s] = dp[j-1][k][s] + dp[j-1][k-1][s-x[j]];
    ll res = 0;
    for(int k = 1; k <= n; ++k)
    {
        res += dp[n][k][k*a];
    }

    cout << res << endl;
}
