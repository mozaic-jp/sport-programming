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

unsigned gcd(unsigned a, unsigned b) {
  if(a < b) return gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;

    vector <ll> a(N);
    ll amax = 0;

    REP(i, N)
    {
        cin >> a[i];
        amax = max(amax, a[i]);
    }
    ll wa = a[0];
    for(int i = 1; i < N; ++i)
    {
        wa = lcm(wa, a[i]);
        if(wa >= MOD * 2)
        {
            cout << 0 << endl;
            return 0;
        }
    }

    //lcmの2が複数含まれてたらおわり
    //↑全部 2*2 で割れてればOK
    if((wa / 2) % 2 == 0)
    {
        cout << 0 << endl;
        return 0;
    } 

    ll res;

    M += (wa / 2);
    res = M / wa;

    cout << res << endl;

    return 0;
}
