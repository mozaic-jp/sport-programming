#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm> // sort
#define REP(i, n) for (long long i = 0; i < (n); i++) 

using namespace std;

typedef long long ll;
typedef std::pair<int, int> pint;
static const ll INF = 1000000000000000000LL;

const int MOD = 1000000007;
//行える操作: 整数 i ( 1 ≤ i ≤ N − 1 ) を一つ選ぶ。 
//左から i 番目のカードと i + 1 番目のカードの位置を入れ替え、さらにこれら 2 枚のカードを裏返す。

//可能性のある数列と移動回数が求められればよい

//奇数回の移動先ではbになる
//bの数は偶数個になる

//dpでやる
//dp[bit][s]: N枚のカードのうち、bitで表されるものについては
//左詰めソートされている状態で、
//最後の値がsである状態にするまでに必要な最小回数
//s: a,bの最大の値
//sortedはbit == 0からはじめてsortedになるやつが埋められるイメージ

int main(){
        
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
    
    int N;
    cin >> N;
    vector <int> a(N);
    vector <int> b(N);

    REP(i, N)cin >> a[i];
    REP(i, N)cin >> b[i];
    //奇数回の移動先ではbになる
    //010101
    //すべてa[i]の状態がうえとする
    //a,bの最大は50
    vector <vector <int> > dp((1<<N) + 1, vector <int> (55, MOD));
    dp[0][0] = 0;

    for(int bit = 0; bit < (1 << N); ++bit)
    {
        //bitで表される数?
        int con = 0;
        for(int i = 0; i < N; ++i)if(bit &(1 << i))++con;

        //bit に含まれない残りの要素が何番目に対応するか
        vector <pint> ords;
        int iter = con;
        for(int i = 0; i < N; ++i)
        {
            //bitに含まれなければ
            if(!(bit & (1 << i)))
            {
                ords.emplace_back(i, iter++);
            }
        }

        for(int s = 0; s <= 50; ++s)
        {
            if(dp[bit][s] >= MOD)continue;

            for(auto p:ords)
            {
                //p.first もともとのaのindex
                //p.second dp[bit][s]の状態のindex
                int ns = -1;
                //
                if(abs(p.first - con) % 2 == 0)
                {
                    ns = a[p.first];
                }
                else
                {
                    ns = b[p.first];
                }
                if(ns >= s)
                {
                    //できた部分からorで埋めてく　 転倒数を足す
                    dp[bit|(1<<p.first)][ns] = min(dp[bit|(1<<p.first)][ns], dp[bit][s] + abs(p.second - con));
                }
            }
        }
    }
    int res = MOD;
    for(int s = 0; s <= 50; ++s)
    {
        res = min(res, dp[(1<<N) - 1][s]);
    }
    if(res >= MOD)res = -1;

    cout << res << endl;

    return 0;    
}
