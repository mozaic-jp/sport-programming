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
    int H,N;
    cin >> H >> N;
    vector <int> a(N);
    ll sum_a = 0;
    REP(i, N)
    {
        cin >> a[i];
        sum_a += a[i];
    }

    string res = "No";

    if(sum_a >= H)res = "Yes";


    cout << res << endl;


    return 0;
}