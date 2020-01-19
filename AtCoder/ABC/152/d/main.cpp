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
    int N;
    cin >> N;
    //先頭がiで終わるやつの数
    //先頭がiで終わるやつの数

    vector <vector<int> > sen(10, vector<int>(10, 0));

    for(int i = 1; i <= N; ++i)
    {
        string tmp = to_string(i);

        sen[tmp[0] - '0'][tmp[tmp.size()-1] - '0']++;
    }

    int res = 0;
    for(int i = 1; i <= 9; ++i)
    {
        for(int j = 1; j <= 9; ++j)
        {
            //
            res += sen[i][j] * sen[j][i];
        }
    }



    cout << res << endl;

    return 0;
}
