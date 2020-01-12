#include <iostream>
#include <fstream>
#include <algorithm>       // for next_permutation
#include <vector>
#include <queue>
#include <bits/stl_numeric.h>
#include <math.h>

#define DEBUG 0
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;

long modPow(long x, long n, long m){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return modPow(x * x % m, n / 2, m);
  else
    return x * modPow(x, n - 1, m) % m;
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;

    vector <ll> c(N);

    REP(i, N)
    {
        cin >> c[i];
    }
    sort(c.rbegin(), c.rend());

    ll tmp3 = modPow(2, N * 2 - 2, MOD);
    ll tmp2 = tmp3 * 2 % MOD;
    ll res = 0;

    REP(i,N)
    {
        ll tmp;
        tmp = tmp2 * c[i] % MOD;

        res += tmp;
        res %= MOD;

        tmp2 += tmp3;
        tmp2 %= MOD;
    }

    cout << res << endl;

    return 0;
}
