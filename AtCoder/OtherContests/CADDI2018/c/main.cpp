#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll INF = 1000000000000000000LL;
using namespace std;


const int MOD = 1000000007;

vector <ll>  get_divisor(ll n)
{
  vector <ll> res;
  for(ll i = 2; i * i <= n; ++i)
  {
    while(n % i == 0)
    {
      res.push_back(i);
      n /= i; 
    }
  }
  if(n != 1)
  {
    res.push_back(n);
  }

  return res;
}

int main() {
    ll N,P;
    cin >> N >> P;

    if(N == 1)
    {
        cout << P << endl;
        return 0;
    }

    //Pを2で何回われるか試す
    //より大きかったら1を返す
    ll cnt = 0;
    ll p = 1;
    while(p < P)
    {
      p *= 2;
      ++cnt;
    }
    if(cnt < N)
    {
      cout << 1 << endl;
      return 0;
    }
    //公約数を数え上げて、N個に振り分ける 
    vector <ll> waruList;
    

    waruList = get_divisor(P);

    //for(auto v: waruList)
    //{
    //    cout << v << endl;
    //}
    int res = 1;

    for(int i = 0; i+N-1 < waruList.size(); ++i)
    {
        if(waruList[i] == waruList[i+N-1])
        {
            res *= waruList[i];
            i += N - 1;
        }
    }

    cout << res << endl;

    return 0;
}

