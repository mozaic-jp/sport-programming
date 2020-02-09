#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <bits/stdc++.h>

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;

using Graph = vector<vector<int>>;

typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;

//個数制限なしナップサック(重複)

int main()
{
    ll H,N;
    cin >> H >> N;
    vector <int> a(N);
    vector <int> b(N);
    REP(i,N)
    {
        cin >> a[i]>> b[i];
    }

    vector <vector<ll> > dp(N+1, vector<ll>(H+1, INF));
    dp[0][0] = 0;

    //dp[i][H]: H与えたときの最小の使用魔力

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j <= H; ++j)
        {
            if(j < a[i])
            {
                dp[i+1][j] = dp[i][j];
            }
            else
            {
                dp[i+1][j] = min(dp[i][j], dp[i+1][j-a[i]] + b[i]);
            }
        }
    }



    //最後にhを超えてもいいというルールを適用する
    for(int i = 0; i < N; ++i)
    {
        //a[i]
        if(H-a[i] > 0)
        {
            for(int j = H - a[i]; j < H; ++j)
            {
                dp[N][H] = min(dp[N][H], dp[N][j] + b[i]);
            }
        }
        else
        {
            dp[N][H] = min(dp[N][H], (ll)b[i]);
        }
    }

    ll res = 0;
    res = dp[N][H];

    cout << res << endl;


    return 0;
}