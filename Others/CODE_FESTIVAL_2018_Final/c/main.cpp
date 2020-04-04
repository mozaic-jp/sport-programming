#include <iostream>
#include <fstream>
#include <algorithm>       // for next_permutation
#include <vector>
#include <queue>
#include <bits/stl_numeric.h>

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;

typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;


int main()
{
    int n;
    cin >> n;
    vector <pair<ll, ll>> ab(n);
    REP(i,n)cin >> ab[i].first >> ab[i].second;
    sort(ab.begin(),ab.end());

    ab.push_back({MOD,MOD+MOD});

    int m;
    cin >> m;
    vector<ll> t(m);
    REP(i,m)cin >> t[i];
    //通話時間がAi分の場合には他のどのプランよりも
    //通話料金が1円以上安くなることが保証されます
    //より、lower_boundして、一個前と比較して安い方、でいい気がする

    REP(i,m)
    {
        int res;
        auto po = lower_bound(ab.begin(),ab.end(),make_pair(t[i],-1ll))- ab.begin();
        if(po-1<0)
        {
            //t[i] <= ab[i].first
            res = ab[po].second;
        }
        else
        {
            res = min(ab[po].second, ab[po-1].second + t[i] - ab[po-1].first);
        }
        cout << res << endl;
    }

    return 0;
}