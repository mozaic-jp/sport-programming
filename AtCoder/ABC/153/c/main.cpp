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
    int N,K;
    cin >> N >> K;
    vector <int> h(N);
    REP(i,N)cin >> h[i];
    sort(h.rbegin(),h.rend());

    ll res = 0;
    for(int i = K; i < N; ++i)
    {
        res += h[i];
    }
    cout << res << endl;
    return 0;
}