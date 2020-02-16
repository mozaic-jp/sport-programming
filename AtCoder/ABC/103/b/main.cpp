#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); ++i) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;

using namespace std;


int main(){
  ll N,res;
  cin >> N;

  if(N % 2 == 0)
  {
    N--;
  }


  res = 0;

  for(ll j = 105; j <= N; j+=2)
  {
    //jは入れておく
    ll cnt = 1;

    for(ll i = 1; i <= j/2 + 1; i+=2)
    {
  
      if(j % i == 0)
      {
        cnt++;
      }
    }
  
    if(cnt >= 8)
    {
      res++;
    }
  }

  cout << res << endl;
  return 0;
}
