#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(long long i=(a),i##Len_=(b);i<i##Len_;i++)
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;



int main()
{
    ll W,H;

    string res;
    cin >> W >> H;

    if(W / 4 * 3 == H)res = "4:3";
    else res = "16:9";

    cout << res << endl;
    return 0;
}

