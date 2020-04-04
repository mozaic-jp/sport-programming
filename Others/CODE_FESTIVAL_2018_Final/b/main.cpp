#include <iostream>
#include <vector>
#include <cmath>

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;

typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;

//それぞれの人が同確率でどれかの色 1つに投票するとき
//投票結果がちょうどr[i]となる

//3 2
//1 2
//の場合: 3C1 / 2^3
//3/8

// p≥10^(−x)
// x = 1: 1/10
// x = 2: 1/100
// log10(p) >= (-x)
//pが10^(-n)となるか
const int MAX = 101010;
vector<long double> p;

int main()
{
    int n;//投票数
    int m;//カラー数
    cin >> n >> m;

    p.assign(MAX, 0);
    //それぞれの対数を取得
    //p[1] = 1 の対数
    //p[2] = (1 * 1/2) の対数
    for(int i = 1; i < MAX; ++i)
    {
        p[i] = p[i-1] + log10(i);
    }
    
    //REP(i,11)cout << p[i] << endl;
    
    //NCN-r_1 ×N-r_1CN-r_1-r_2 ×…× r_NC0の　左の全体
    //1*1/2*...1/N の小数点以下の桁数
    long double prob = -p[n];

    REP(i,m)
    {
        int r;
        cin >> r;
        //nCr[i]の右のやつ
        prob += p[r];

    }
    //M^N
    prob += log10(m) * n;
    
    cout << ceil(prob) << endl;
    return 0;
}