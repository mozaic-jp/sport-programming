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
    ll H,W,N,res;
    cin >> H >> W >> N;

    res = (N-1) / max(H,W) + 1;

    cout << res << endl;

    return 0;    
}
