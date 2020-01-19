#include <iostream>
#include <fstream>
#include <algorithm>       // for next_permutation
#include <vector>
#include <queue>
#include <bits/stl_numeric.h>
#include <math.h>
#include <map>

#define DEBUG 0
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;


// mod. m での a の逆元 a^{-1} を計算する
// a * a^(p−2) ≡ 1(mod p)
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

bool isPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

vector <ll>  get_divisor(ll n)
{
  vector <ll> res;
  for(ll i = 2; i * i <= n; ++i)
  {
    while(n % i == 0)
    {
      res.push_back(i);
      n /= i; 
    }
  }
  if(n != 1)
  {
    res.push_back(n);
  }

  return res;
}

//最小公倍数の約数のリストのほうがいいかな

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector <ll> a(N);
    REP(i, N)cin >> a[i];

    vector<ll> now = a;
    map <ll, ll> m;
    //素因数分解
    for(ll i = 0; i < N; ++i)
    {
        for (ll j = 2; j*j <= now[i]; ++j) {
            ll cnt = 0;
            while(now[i] % j == 0)
            {
                ++cnt;
                now[i] /= j;
            }
            m[j] = max(m[j], cnt);
        }
        m[now[i]] = max(m[now[i]], 1LL);
    }

    ll ans = 1;
    for(auto v: m)
    {
        for(int i = 0; i < v.second; ++i)
        {
            ans *= v.first;
            ans %= MOD;
        }
    }
    ll res = 0;
    for(int i = 0; i < N; ++i)
    {
        ll tmp = ans * modinv(a[i], MOD);
        res += tmp;
        res %= MOD;
    }

    cout << res << endl;

    return 0;
}
