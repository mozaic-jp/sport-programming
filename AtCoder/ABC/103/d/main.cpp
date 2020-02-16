#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(long long i=(a),i##Len_=(b);i<i##Len_;i++)
typedef long long ll;
typedef pair<long long, long long> pll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;

//N M Q
//M本の電車区間
//Qの範囲に収まるM


//𝑥𝑙,𝑟 を 区間 [𝑙, 𝑟] を走る列車の個数、とします。
//クエリ (𝑝, 𝑞) に対して、
//求めたい値は 𝑥𝑝,𝑝 + 𝑥𝑝,𝑝+1 + ⋯ + 𝑥𝑝,𝑞 + 𝑥𝑝+1,𝑝 + ⋯ + 𝑥𝑞,𝑞　となる
//L < Rのため、実際には半分

//二次元累積
int main() {

    ll N,M,S;

    cin >> N >> M >> S;

    ll tmp1,tmp2;

    ll LR[N][N] = {};
    REP(i,M)
    {
        cin >> tmp1 >> tmp2;

        --tmp1;--tmp2;
        ++LR[tmp1][tmp2];
    }

    //ソートすることで

    ll ruiseki[N+1][N+1] = {};

    REP(i,N)
    {
        REP(j,N)
        {
            ruiseki[i+1][j+1] = ruiseki[i][j+1] + ruiseki[i+1][j] - ruiseki[i][j] + LR[i][j];
        }
    }

    //vector <pair<pll,ll>> PQ(Q);
    ll P,Q;
    REP(i,S)
    {
        cin >> P >> Q;
        --P;

        ll res = ruiseki[Q][Q] - ruiseki[P][Q] - ruiseki[Q][P] + ruiseki[P][P];

        cout << res << endl;
    }

    //都市[2][3] -> [2][2],[2][3],[3][3]


    return 0;
    
}
