#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(long long i=(a),i##Len_=(b);i<i##Len_;i++)
typedef long long ll;
static const ll MOD = 1000000007;


//arc090
//いつのタイミングで、下に行くか



int main()
{
    ll N;

    cin >> N;

    ll dp[N+1][2] = {};
    ll a[N+1][2] = {};


    REP(i,N)
    {
        cin >> a[i][0];
    }
    REP(i,N)
    {
        cin >> a[i][1];
    }

    dp[0][0] = a[0][0];

    if(N == 1)
    {
        cout << a[0][0] + a[0][1] << endl;
        return 0;
    }

    for(ll i = 0; i < N-1 ; ++i)
    {
        dp[i][1] = max(dp[i][1], dp[i][0] + a[i][1]);
        for(ll j = 0; j <=1; ++j)
        {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a[i+1][j]);
        }
    }

    cout << dp[N-1][1] << endl;

}

