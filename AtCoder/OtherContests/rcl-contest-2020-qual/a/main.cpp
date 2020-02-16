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
const int MAX = 2100000;
const int MOD = 1000000007;

//モノスで高得点を出す方法
//段がすべて埋め尽くされると得点を獲得
// その段に配置された色別の価値の合計を求める
// 色別の価値の合計のうち最大のものを得点として得る
//段をなるべく同色でまとめたほうがよい

int main()
{
    int N,W,K,V;
    cin >> N >> W >> K >> V;
    vector <pair<int,int>> cv(N);

    REP(i,N)
    {
        cin >> cv[i].first >> cv[i].second;
    }

    //方針1:とりあえず平たく並べる

    REP(i,N)
    {
        cout << i % W << endl;
    }
    return 0;
}