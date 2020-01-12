#include <iostream>
#include <fstream>
#include <algorithm>       // for next_permutation
#include <vector>
#include <bits/stl_numeric.h>

#define DEBUG 0
#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;

//方針
//変換して -> 変換して出力

int main() {
    int N;
    char target[10];
    REP(i, 10)cin >> target[i];
    cin >> N;

    vector <string> s(N);
    vector <ll> a(N);
    REP(i, N)
    {
        cin >> s[i];

        string tmp = "";

        REP(j, s[i].size())
        {
            REP(k, 10)
            {
                if(target[k] == s[i][j])
                {
                    tmp += to_string(k);
                }
            }
        }

        a[i] = stol(tmp);
    }

    


    sort(a.begin(), a.end());

    REP(i, N)
    {
        string res = "";
        string tmp = to_string(a[i]);
        //cout << tmp << endl;

        REP(j, tmp.size())
        {
            res += target[tmp[j] - '0'];
        }

        cout << res << endl;
    }
    return 0;
}
