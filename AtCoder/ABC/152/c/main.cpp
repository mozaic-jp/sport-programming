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
    int n;
    cin >> n;
    int res = 0;
    vector <int> p(n);
    REP(i,n)cin >> p[i];
    vector <int> ok(n, 0);

    int iMin = MOD;

    for(int i = 0; i < n; ++i)
    {
        iMin = min(iMin, p[i]);

        if(iMin == p[i])++res;

    }


    cout << res << endl;

    return 0;
}
