#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <map>

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;


typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;

int main()
{
    int N,P;
    cin >> N >> P;
    int res;
    vector <int> c(N);
    REP(i,N)cin >> c[i];
    int coupon = 0;
    REP(i,N)
    {
        if(P < c[i])continue;
        coupon = max(coupon, c[i]);
    }
    res = P - coupon;


    cout << res << endl;

    return 0;
}