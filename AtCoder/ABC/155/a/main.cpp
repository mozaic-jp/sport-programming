#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define vl vector<ll>
#define vvl vector< vector<ll> >
#define REP(i, n) for (long long i = 0; i < (n); i++) 
#define all(c) c.begin(),c.end()
#define fio() cin.tie(0); ios::sync_with_stdio(false);

static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    string res = "No";

    if(a == b && b != c)res = "Yes";
    if(b == c && c != a)res = "Yes";
    if(c == a && a != b)res = "Yes";

    cout << res << endl;

    return 0;
}