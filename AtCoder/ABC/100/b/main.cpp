#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;

//10000は100で2回割り切れてしまうので、D==1のときはいれない
int main(){
  ll D,N;
  cin >> D >> N;

  ll res = 1;
  REP(i,D)
  {
    res *= 100;
  }
  if(N == 100)N++;

  cout << res * N << endl;

  return 0;

}
