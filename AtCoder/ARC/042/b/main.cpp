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


typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;


//https://perogram.hateblo.jp/entry/arc042_b

//3-10角形

//多角形の頂点が与えられる
//点と辺の最短距離を求める
//板の頂点の与えられる順番が決まっているからそれでよさそう
typedef complex<double> cd;
 
double distance(cd p0, cd c1, cd c2){
    // c1原点に移動
    p0 -= c1;
    c2 -= c1;
 
    // 回転
    auto u = c2 / abs(c2);
    p0 /= u;
 
    return p0.imag();
}

int main()
{
    ll x, y;
    cin >> x >> y;
    complex <double> A(x,y);

    int N;
    cin >> N;
    vector<complex<double> > C(N);
    vector <pair<int,int> > xy(N+1);
    REP(i,N)
    {
        cin >> xy[i].first >> xy[i].second;
        C[i].real(xy[i].first);
        C[i].imag(xy[i].second);
    }
    C.push_back(C[0]);

    xy[N] = xy[0];

    double res = 10000;

    for(int i = 0; i < N; ++i)
    {
        double d = distance(A,C[i],C[i+1]);
        res = min(res, d);
        //回転させるには、 値 / b * |ab|

        //距離 d = ysinθ
        //|x||y|sinθ = x * y
        // d = x * y / |x|

    }

    printf("%.12f\n", res);
    return 0;
} 