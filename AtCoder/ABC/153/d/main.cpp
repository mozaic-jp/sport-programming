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
    ll H;
    cin >> H;
    ll res = 0;
    ll kake = 1;

    while(H != 0)
    {
        res += kake;
        H /= 2;
        kake *= 2;
    }


    cout << res << endl;


    return 0;
}