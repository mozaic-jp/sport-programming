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

//(N-1)!をかけると、総和を求めればよいだけになる?
//移動の順序によって、距離の総和が異なる
// x[N-1]は必ず、1の移動になる
// x[N-2]は、1 or 2 (確率は1/2)
// x[N-3]は、1 or 2 or 3 

long long v[100009];
long long fact[100009], factinv[100009];

long long modPow(long long x, long long n, long long m){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return modPow(x * x % m, n / 2, m);
  else
    return x * modPow(x, n - 1, m) % m;
}


long long Div(long long a, long long b, long long m) {
	return (a * modPow(b, m - 2, m)) % m;
}
//二項係数　nCr
//fact: N!
//factinv: fact[]のmodの逆元　a * a^(p-2) ≡ 1 (mod p)
//v:最大値の総移動回数
//(全通りの組合せを考えると、N==4のとき、3から4への移動を11回行う。N==5のとき、4から5への移動を50回)
void init() {
	fact[0] = 1;
	for (int i = 1; i <= 100000; i++) fact[i] = (1LL * fact[i - 1] * i) % MOD;
	for (int i = 0; i <= 100000; i++) factinv[i] = Div(1, fact[i], MOD);
	v[0] = 0;
	for (int i = 1; i <= 100000; i++) v[i] = (1LL * i * v[i - 1] + fact[i - 1]) % MOD;
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector <ll> x(N+1);
    REP(i,N)
    {
        cin >> x[i+1];
    }
    init();

    ll res = 0;
    for(int i = 1; i <= N-1; ++i)
    {
        ll val = v[i];
        val *= fact[N-1];
        val %= MOD;
        val *= factinv[i];
        val %= MOD;
        res += val * (x[i+1] - x[i]);
        res %= MOD;
    }



    cout << res << endl;


    return 0;
}
