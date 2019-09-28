#include <iostream>
#include <fstream>
#include <vector>

#define DEBUG 0

using namespace std;
#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;

//https://atcoder.jp/contests/abc039/tasks/abc039_c

int main(){

#if DEBUG
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    string s;
    cin >> s;

    string kenban[] = {"Do", "Do", "Re", "Re", "Mi", "Fa", "Fa", "So", "So", "La", "La", "Si"};

    string tar = "WBWBWB";

    int offset;
    REP(i,s.size() - 5)
    {
        string tmp = s.substr(i, tar.size());
        if(tmp == tar)
        {
            offset = i;
            break;
        }
    }

    //offset -> ファの位置
    //12 -> 0
    //6  -> 11
    //5  -> 0
    //0  -> 5

    ll j = 5 - offset;
    if(j < 0)j += 12;

    string res = kenban[j];


    cout << res << endl;
}
