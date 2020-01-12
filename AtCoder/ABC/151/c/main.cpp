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
    ll N, M;
    cin >> N >> M;
    vector <int> a(N, 0);
    vector <int> wa(N, 0);

    ll ac = 0;
    ll souwa = 0;
    //最終的にwaのままの場合は、ペナに足さない

    REP(i, M)
    {
        int p;
        string s;
        cin >> p >> s;
        --p;
        if(s[0] == 'A')//AC
        {
            if(a[p] == 0)
            {
                ++ac;
                a[p] = 1;
            }
        }
        else
        {
            if(a[p] == 0)
            {
                ++wa[p];
            }
        }
    }

    REP(i,N)
    {
        if(a[i] == 1)
        {
            souwa += wa[i];
        }

    }

    cout << ac << " " << souwa << endl;

    return 0;
}
