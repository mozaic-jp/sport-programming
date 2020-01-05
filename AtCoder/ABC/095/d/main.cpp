#include <iostream>
#include <fstream>
#include <algorithm>       // for next_permutation
#include <vector>
#include <bits/stl_numeric.h>

#define DEBUG 0
#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;


ll N,C;
int main() {
    cin >> N >> C;
    //メートル
    vector <ll> x(N);
    //カロリー
    vector <ll> c(N);
    ll sum = 0;
    REP(i,N)
    {
        cin >> x[i] >> c[i];
        sum += c[i];
    }


    //最大値のとりかたは、区間になるはず
    //(1~10)とか (9~2->{9,10,1,2})とか
    //小さい方を2倍のカロリーでとればよい
    //Cの最大値が10^14なので、区間は(N)でとる

    ll res = 0;
    
    //左から(時計回り)舐めたときの値と、(区間:0~i)の値
    vector <pair<ll, ll> > l(N+2);
    //時計回りに往復する
    //->反時計周りの方は、独立して考えられる
    //1回しか移動しないときの最大のAを求めておく
    vector <ll> fl(N+2);
    fl[0] = 0;

    l[0].first = 0;
    l[0].second = 0;
    for(ll i = 0; i < N; ++i)
    {
        l[i+1].first = x[i];
        l[i+1].second = l[i].second + c[i];

        res = max(res, l[i+1].second - l[i+1].first);
        fl[i+1] = max(fl[i], l[i+1].second - l[i+1].first);
    }
    l[N+1].first = C;
    l[N+1].second = sum;
    fl[N+1] = fl[N];

    //右から舐めたときの値をそれぞれとる(区間:i~N-1)の値
    vector <pair<ll, ll> > r(N+2);

    vector <ll> fr(N+2);

    fr[0] = 0;
    r[0].first = C;
    r[0].second = 0;
    for(ll i = 0; i < N; ++i)
    {
        r[i+1].first = x[N-1-i];
        r[i+1].second = r[i].second + c[N-1-i];

        res = max(res, r[i+1].second - (C - r[i+1].first));
        fr[i+1] = max(fr[i], r[i+1].second - (C - r[i+1].first));
    }
    r[N+1].first = 0;
    r[N+1].second = sum;
    fr[N+1] = fr[N];

    //時計回りから
    for(ll i = 0; i < N + 1; ++i)
    {
        ll tmp;
        tmp = l[i].second - 2 * l[i].first + fr[N - i];
        res = max(res, tmp);
    }
    //反時計回り
    for(ll i = 0; i < N + 1; ++i)
    {
        ll tmp;
        tmp = r[i].second - 2 * (C - r[i].first) + fl[N - i];
        res = max(res, tmp);
    }




//    for(ll i = 0; i < N + 2; ++i)
//    {
//        for(ll j = 0; j < N + 2; ++j)
//        {
//            //交差するようなら終了
//            if(l[i].first >= r[j].first)break;
//
//            //消費カロリー
//            ll syohi = l[i].first + C - r[j].first + min(l[i].first, C - r[j].first);
//            //摂取カロリー
//            ll sessyu = l[i].second + r[j].second;
//
//            res = max(res,sessyu - syohi);
//        }
//    }

    cout << res << endl;
    return 0;
}
