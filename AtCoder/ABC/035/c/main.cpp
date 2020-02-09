#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll mod = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;

//裏返った回数を累積和でとっておく
int main(){
    ll N,Q;
    cin >> N >> Q;

    ll l[Q],r[Q];
    ll sa[N+1] = {};
    REP(i,Q)
    {
        cin >> l[i] >> r[i];
        --l[i];
        --r[i];
    }

    REP(i,Q)
    {
        ++sa[l[i]];
        --sa[r[i] + 1];
    }

    REP(i,N)
    {
        if(i > 0)sa[i] += sa[i-1];
    }

    //REP(i,N)cout << sa[i] << endl;
    ll res;
    REP(i,N)
    {
        if(sa[i] % 2 == 0)res = 0;
        else res = 1;

        cout << res;
    }

    cout << endl;


    return 0;
}



