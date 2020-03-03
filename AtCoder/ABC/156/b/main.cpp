#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <bits/stdc++.h>

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;

using Graph = vector<vector<int>>;

typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;


int main()
{
    ll N, K;
    //桁数を回答する

    cin >> N >> K;

    int res = 1;
    for(ll i = K; i <= N; i *= K)
    {
        ++res;
    }

    cout << res << endl;

    return 0;
}