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

//各種類のケーキには「綺麗さ」「おいしさ」「人気度」の 3 つの値をもつ
// 合計の絶対値を取る必要がある
// 

struct Cake
{
    ll beauty,taste,popular;
};

int main()
{
    ll N, M;
    cin >> N >> M;
    vector <ll> x(N);
    vector <ll> y(N);
    vector <ll> z(N);
    REP(i,N)
    {
        cin >> x[i] >> y[i] >> z[i];
    }

    ll res = 0;


    for(int bit = 0; bit < (1 << 3); ++bit)
    {
        vector <ll> sogo(N, 0);
        REP(i, N)
        {
            ll x_i,y_i,z_i;

            if(bit & (1 << 0))
            {
                sogo[i] += -x[i];
            }
            else
            {
                sogo[i] += x[i];
            }
            if(bit & (1 << 1))
            {
                sogo[i] += -y[i];
            }
            else
            {
                sogo[i] += y[i];
            }
            if(bit & (1 << 2))
            {
                sogo[i] += -z[i];
            }
            else
            {
                sogo[i] += z[i];
            }
        }
        sort(sogo.rbegin(), sogo.rend());
        ll tmp = 0;
        REP(i, M)
        {
            tmp += sogo[i];
        }
        res = max(res, tmp);
    }

    cout << res << endl;

    return 0;
}