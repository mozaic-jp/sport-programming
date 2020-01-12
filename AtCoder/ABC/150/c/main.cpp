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

    vector <int> p(N);
    vector <int> q(N);
    vector <int> san(N);

    REP(i, N)
    {
        cin >> p[i];
        san[i] = p[i];
    }
    REP(i, N)
    {
        cin >> q[i];
    }

    sort(san.begin(), san.end());

    ll cnt = 1;
    int a = 0;
    int b = 0;

    do {
        
        bool flag = true;
        for(int i = 0; i < N; ++i)
        {
            if(p[i] != san[i])
            {
                flag = false;
                break;
            }
        }
        if(flag)a = cnt;

        flag = true;
        for(int i = 0; i < N; ++i)
        {
            if(q[i] != san[i])
            {
                flag = false;
                break;
            }
        }
        if(flag)b = cnt;

        if(a != 0 && b != 0)break;
    
        ++cnt;
    } while (std::next_permutation(san.begin(), san.end()));

    res = abs(a-b);

    cout << res << endl;

    return 0;
}
