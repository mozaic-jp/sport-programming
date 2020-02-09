#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm> // sort
#include <iomanip>
#include <queue>
#include <map>
#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll INF = 1000000000000000000LL;
typedef pair<int,int> pint;

using namespace std;

const int MOD = 1000000007;


//dp[j][k][s]: k枚選んで sにする選び方の総数

int main(){

    ll a,b,c,x;
    ll res = 0;
    cin >> a >> b >> c >> x;

    REP(i,a+1)
    {
        REP(j,b+1)
        {
            if(500*i + 100*j > x)break;
            if(x - 500*i - 100*j <= 50*c)++res;
        }
    }
    cout << res << endl;

    return 0;     
}

