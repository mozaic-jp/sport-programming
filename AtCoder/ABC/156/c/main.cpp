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
    int N;
    cin >> N;
    vector <int> x(N);
    REP(i, N)cin >> x[i];

    ll res = INF;

    for(int i = 1; i <= 100; ++i)
    {
        ll tmp = 0;
        for(int j = 0; j < N; ++j)
        {
            tmp += pow(x[j] - i, 2.0);
        }

        res = min(res, tmp);
    }
    cout << res << endl;


    return 0;
}