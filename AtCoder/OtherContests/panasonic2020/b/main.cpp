#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <map>
#include <set> 

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;


typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;

int main()
{
    ll h,w;
    cin >> h >> w;

    ll res = (h * w + 1) / 2;

    if(h == 1 || w == 1) res = 1;

    cout << res << endl;


    return 0;
}