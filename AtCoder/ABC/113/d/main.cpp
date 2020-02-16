#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll INF = 1000000000000000000LL;
using namespace std;

const int MOD = 1000000007;

int main(){
    int H,W,K;
    cin >> H >> W >> K;
    //MAX_H = 100
    //MAX_W = 8

    //あみだくじの全通り
    //H = 2, W = 3のとき、 3^2 = 9通り
    //W = 3のとき、 1-2 or 2-3 or 繋がない の3通り
    //縦棒1から始まるというルールがある
    //9通りの行き先は、1,2,1,2,1,1,3,2,1
    // 
    //線があったとき、なかったときでdpしていけばよい?
    //dp[i][k]: 高さiで位置Kに到達する個数
    //もらうdp

    ll dp[H+1][W];
    for(int i = 0; i < H+1; ++i)
    {
        for(int j = 0; j < W; ++j)
        {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for(int i = 1; i < H+1; ++i)
    {
        //bit 1 -> 0と1につながっている
        for(int bit = 0; bit < (1 << (W-1)); ++bit)
        {
            bool ok = true;
            //線分がつながっていたらout
            for(int x = 0; x < W - 2; ++x)
            {
                if((bit & (1 << x)) && (bit & (1 << (x + 1))))
                {
                    ok = false;
                }
            }
            if(ok)
            {
                for(int j = 0; j < W; ++j)
                {
                    if(bit & (1 << j))
                    {
                        dp[i][j] += dp[i-1][j+1];
                    }
                    else if(j != 0 && (bit & (1 << (j-1))))
                    {
                        dp[i][j] += dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j] += dp[i-1][j];
                    }
                    dp[i][j] %= MOD;
                }
            }

        }

        //線分 0-1,1-2,2-3,3-4...
        //線分 0-1をはやしたときにもdp[2]に追加する

        //線分は、横軸に対して、max(1, W-2)本追加できること(つながっていなければok)
    }

    ll res;
    res = dp[H][K-1];

    //よって、最大 8^100 -> 64bitに収まらない

    //特性として、元々、Kに行く予定のあみだくじ
    //に対して、位置 H の線を Kにつなぐと、Kに行かなくなる

    cout << res << endl;

    return 0;
}

