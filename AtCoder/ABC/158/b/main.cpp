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
    ll n,a,b;
    cin >> n >> a >> b;
    if(a == 0 && b == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    ll res = 0;
    res += (n /(a+b)) * a;
    ll tmp = n % (a+b);
    res += min(tmp, a);

    cout << res << endl;

    return 0;
}