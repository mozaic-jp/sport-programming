#include <iostream>
#include <fstream>
#include <vector>

#define DEBUG 0

using namespace std;
#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;

int main(){

#if DEBUG
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    ll t1,t2,a1,a2,b1,b2;
    ll res;
    cin >> t1 >> t2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;

    ll p,q;
    p = (a1 - b1) * t1;
    q = (a2 - b2) * t2;

    if(p + q == 0)
    {
        cout << "infinity" << endl;
        return 0;
    }

    if(p > 0)
    {
        p *= -1;
        q *= -1;
    }
    if(p + q < 0)res = 0;
    else//p + q > 0
    {
        ll s, t;
        s = (-p) / (p + q);
        t = (-p) % (p + q);
        if(t != 0)
        {
            res = s * 2 + 1;
        }
        else
        {
            res = s * 2;
        }
        
    }

    cout << res << endl;
    return 0;
}
