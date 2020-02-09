#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <math.h> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;

//F
//遠くにいく
//X,Yのabsの最大
int main(){
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    ll x,a,b;
    cin >> x >> a >> b;

    ll res = 0;

    x -= a;

    res = x % b;

    cout << res << endl;


    return 0;    

}

