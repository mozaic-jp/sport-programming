#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <bits/stdc++.h>

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll INF = 1000000000000000000LL;
using namespace std;
vector<ll> weight, value;
ll dp[105][20050];

int main()
{
    int M,K;
    cin >> M >> K;

    //(2k + 1)^n - 1
    //---------------
    //       2

    //がM以上となるNを探す

    ll res = M;
    for(int i = 1; i <= M; ++i)
    {
        ll tmp;
        tmp = pow((2 * K + 1),i) - 1;
        tmp /= 2;
        if(tmp >= M)
        {
            res = i;
            break;
        }
    }

    cout << res << endl;
    return 0;
}