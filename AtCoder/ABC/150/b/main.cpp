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
    int res = 0;
    string s;
    cin >> s;

    for(int i = 0; i < N - 2; ++i)
    {
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C')
        {
            ++res;
        }
    }


    cout << res << endl;

    return 0;
}
