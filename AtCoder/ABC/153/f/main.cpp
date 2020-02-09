#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <bits/stdc++.h>

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;

using Graph = vector<vector<int>>;

typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,D,A;
    cin >> N >> D >> A;
    vector<pair<ll,ll>> mon(N);
    REP(i,N)
    {
        cin >> mon[i].first >> mon[i].second;
    }

    //スライディング最大値を範囲Dで覚えておく

    //座標でソート
    sort(mon.begin(),mon.end());

    //スライド最小値
    //範囲Dにおける
    ll res = 0;

    //端から順にやってく

    for(int i = 0; i < N; ++i)
    {
        if(mon[i].second <= 0)continue;

        //ichiを二分探索
        auto it = upper_bound(mon.begin(), mon.end(), make_pair(mon[i].first + D * 2,INF)) - mon.begin();

        ll tmp = mon[i].second;
        //for(int j = i; j < it; ++j)
        //{
        //    tmp = max(tmp, mon[j].second);
        //}

        //cout << mon[i].first + D * 2 << endl;
        //cout << it << endl;
        for(int j = i; j < it; ++j)
        {
            mon[j].second -= tmp;
        }

        res += (tmp-1) / A + 1;
        //cout << tmp << endl;
        //cout << A << endl;
        //cout << res << endl;
    }

    cout << res << endl;

    return 0;
}