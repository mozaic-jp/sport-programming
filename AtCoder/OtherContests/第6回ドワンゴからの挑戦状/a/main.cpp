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
    ll N;
    cin >> N;
    vector <string> s(N);
    vector <ll> t(N);
    REP(i,N)
    {
        cin >> s[i] >> t[i];
    }
    string tar;
    cin >> tar;
    
    int cnt;
    REP(i, N)
    {
        if(tar == s[i])
        {
            cnt = i;
            break;
        }
    }
    ll res = 0;
    for(int i = cnt + 1; i < N; ++i)
    {
        res += t[i];
    }

    cout << res << endl;

    return 0;
}
