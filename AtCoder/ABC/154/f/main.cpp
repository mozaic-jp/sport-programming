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
const int MAX = 2100000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];
//経路
//コンビネーション
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main()
{
    int r1,r2,c1,c2;
    cin >> r1 >> c1 >> r2 >> c2;

    COMinit();

    ll res = 0;
    for(int i = c1; i <= c2; ++i)
    {
        ll tmp;
        tmp = COM(r2+i+1,i+1) - COM(r1+i,i+1);
        if(tmp < 0)tmp += MOD;
        tmp %= MOD;
        res += tmp;
        res %= MOD;
    }

    cout << res << endl;

    return 0;
}