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


//https://docs.google.com/presentation/d/1P1Q29KmlCCBbLq1qtpQCC_VN6Rrg48kEqXhmsOLkMQk/edit#slide=id.g7ebf7c8b09_0_9


//5の場合
//    3
//   43
//  243
// 5243
//15243

//奇数番目は一意に決まる
//偶数番目は、(N-1) * (N-3) ...* 2

int main()
{
    int N;
    cin >> N;
    ll res = 1;
    //2 ^ (n/2)

    for(int i = 2; i <= N; i+=2)
    {
        res *= i;
        res %= MOD;
    }

    cout << res << endl;

    return 0;
}