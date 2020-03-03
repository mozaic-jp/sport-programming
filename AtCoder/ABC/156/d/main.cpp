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

//二項係数ライブラリ Binomial coefficient
// constexpr: constant expression 定数式
template<class T> struct BiCoef {
 
    vector<T> fact_, inv_, finv_;
    constexpr BiCoef() {}
//    constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) 
    constexpr BiCoef(int n)
    {
        init(n);
    }
    constexpr void init(int n) noexcept 
    {
        fact_.assign(n,1),inv_.assign(n,1),finv_.assign(n,1);
        //int MOD = fact_[0].getmod();
        for(int i = 2; i < n; ++i)
        {
            //累積積
            fact_[i] = fact_[i-1] * i % MOD;
            //- をつける?
            inv_[i] = MOD - inv_[MOD%i] * (MOD/i) % MOD;
            finv_[i] = finv_[i-1] * inv_[i] % MOD;
        }
    }
 
    //nCk = n! * (n-k)!^-1 * k!^-1
    //nCk = n! / ((n-k)! * k!)
    constexpr T com(int n, int k) const noexcept {
        if (n < k || n < 0 || k < 0) return 0;
        return fact_[n] * (finv_[k] * finv_[n-k] % MOD) % MOD;
    }
 
};
 
BiCoef<ll> bc;
int n,a,b;
int main() {
    cin >> n >> a >> b;
    bc.init(110000);

    //ll res = 2^10^9 - 1
    



    return 0;
}
