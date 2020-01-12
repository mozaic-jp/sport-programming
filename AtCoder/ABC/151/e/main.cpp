#include <iostream>
#include <fstream>
#include <algorithm>       // for next_permutation
#include <vector>
#include <queue>
#include <bits/stl_numeric.h>

#define DEBUG 0
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;

const int MAX = 210000;

long long fac[MAX], finv[MAX], inv[MAX];

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

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    // 前処理
    COMinit();
    ll N, K;
    cin >> N >> K;
    vector <ll> a(N);

    REP(i, N)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    ll res = 0;

    for(int i = N - 1; i - (K-1) >= 0; --i)
    {
        if(a[i] < 0)
        {
            ll tmp = -a[i] * COM(i, K-1);
            tmp %= MOD;
            res -= tmp;
        }
        else
        {
            ll tmp = a[i] * COM(i, K-1);
            tmp %= MOD;
            res += tmp;
        }
        if(res < 0)
        {
            res += MOD;
        }
        else
        {
            res %= MOD;
        }
    }
    for(int i = 0; i + (K-1) < N; ++i)
    {
        if(a[i] < 0)
        {
            ll tmp = (-a[i] * COM(N-1-i,K-1) % MOD);
            res += tmp;
        }
        else
        {
            ll tmp = (a[i] * COM(N-1-i,K-1) % MOD);
            res -= tmp;
        }
        
        if(res < 0)
        {
            res += MOD;
        }
        else
        {
            res %= MOD;
        }
        
        
    }


    cout << res << endl;
}