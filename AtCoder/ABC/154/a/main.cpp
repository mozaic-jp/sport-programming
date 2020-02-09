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


typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;


int main()
{
    string s,t,u;
    cin >> s;
    cin >> t;
    int  N,M;
    cin >> N >> M;
    cin >> u;

    if(s == u)--N;
    if(t == u)--M;

    cout << N << " " << M << endl;

    return 0;
}