#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll INF = 1000000000000000000LL;
using namespace std;

const int MOD = 1000000007;

int main(){
    int N,D,A;
    cin >> N >> D >> A;
    vector <pair<int,int> >  xh(N);

    REP(i, N)
    {
        cin >> xh[i].first >> xh[i].second;
        //あらかじめ圧縮しておく
        xh[i].second = (xh[i].second+A-1)/A;
    }
    sort(xh.begin(),xh.end());
    vector<int>s(N+1);
    int r = 0;
    ll ans = 0;
    REP(i,N)
    {
        xh[i].second -= s[i];
        //rの位置を移動
        while(r < N && xh[r].first <= xh[i].first + 2 * D)++r;
        if(xh[i].second > 0)
        {

            int num =xh[i].second;
            ans += num;
            s[i] += num;
            s[r] -= num;
        }
        //rの範囲でなくても引き継いでよいのか?
        //-> rの範囲でなければ、s[r]がひかれているはず
        //s[i]を引き継ぐ
        s[i+1] += s[i];
    }

    cout << ans << endl;



    return 0;    
}
