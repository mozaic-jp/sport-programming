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
    int N;
    cin >> N;
    //各ペアから選び取る
    //dp[i+1][j]: dp[i][j]とのgcd
    //13 4
    //13 4
    //1  4
    
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