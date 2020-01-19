#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll INF = 1000000000000000000LL;
using namespace std;

const int MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;//N頂点M個のクエリ
    cin >> N >> M;
    vector <int> g(N);

    REP(i,M)
    {
        int a,b;
        cin >> a >> b;
        --a;--b;
        ++g[a];
        ++g[b];
    }

    string res = "YES";

    REP(i,N)
    {
        if(g[i] % 2 == 1)
        {
            res = "NO";
            break;
        }
    }

    cout << res << endl;



    return 0;    
}
