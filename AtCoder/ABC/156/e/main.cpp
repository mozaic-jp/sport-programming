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


typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;

//部屋の移動
//k回後の組み合わせ
//移動は1回何人でも移動して良いただし、隣にしか移動できない


//xHy x種類のものから重複を許してy個選ぶ(重複組合せ)
//xHy = (x+y-1)C(x-1)
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


int main()
{
    int n, k;
    cin >> n >> k;
    //k回で移動できるのは、
    //距離がk以下のところまで
    //0人の部屋やk個以下となる

    //m = 0,1,2,3,4,5

    //nCm ×(n−m)Hm
    //ci = 0がmとなるような数列の数
    //xHy x種類のものから重複を許してy個選ぶ(重複組合せ)
    //xHy = (x+y-1)C(x-1)

    //m = 0,1,2,...n-1

    COMinit();
    ll res = 0;
    for(int m = 0; m <= min(n-1, k); ++m)
    {
        ll tmp;
        tmp = COM(n,m) * COM(n - m + m - 1, n-m-1);
        res += tmp;
        res %= MOD;
    }

    cout << res << endl;
    return 0;
}