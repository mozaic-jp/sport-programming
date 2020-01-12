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


int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K, M;
    cin >> N >> K >> M;
    ll sum = 0;

    REP(i, N -1)
    {
        int a;
        cin >> a;
        sum += a;
    }
    ll res = 0;

    res = N * M - sum;

    if(res > K)
    {
        cout << -1 << endl;
    } 
    else
    {
        cout << max(0ll, res) << endl;
    }

    return 0;
}
