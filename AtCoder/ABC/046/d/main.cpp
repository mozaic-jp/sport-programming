#include <iostream>
#include <fstream>
#include <vector>

#define DEBUG 0

using namespace std;
#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;

//https://atcoder.jp/contests/abc046/tasks/arc062_b

int main(){

#if DEBUG
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    string s;
    cin >> s;

    // (今までにパーを出した回数) <=(今までにグーを出した回数)
    //最初はg確定

    //得点(勝ったターンの数) − (負けたターンの数)
    //勝ちと負けは同じ価値
    //gでは勝つことはできない
    //2/3 g -> 0
    //1/3 g -> -1
    //0/3 g -> -2
    //7/10 g -> 2

    int gCnt = 0;
    REP(i,s.size())
    {
        if(s[i] == 'g')++gCnt;
    }

    int han = (s.size()+1)/2;

    int res = gCnt - han;

    cout << res << endl;
}
