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

vector< vector< pair<int,int> > > v(100010);	
int V[100010] = {0};
int X[100010] = {0};
typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;

ll N,A,B;

bool isOK(ll i, vector <ll> h)
{
    ll kai = 0;
    // i で達成できるか
    ll zenin = B * i;
    REP(i, N)
    {
        ll zan = h[i] - zenin;
        if(zan <= 0)break;
        kai += (zan - 1)/ (A-B) + 1;
    }

    if(kai <= i)return true;
    else return false;
}

int main()
{
    cin >> N >> A >> B;

    vector<ll> h(N);
    REP(i,N)cin >> h[i];

    sort(h.rbegin(), h.rend());
    ll zenin = 0;

    //1から10^5の二分探索

    ll l = 0;
    ll r = 1000000000;
    while(l + 1 < r)
    {
        ll m = (l + r) / 2;

        if(isOK(m, h))
        {
            //cout << m << endl;
            r = m;
        }
        else l = m;

    }
    ll res = r;

    cout << res << endl;

    return 0;
}