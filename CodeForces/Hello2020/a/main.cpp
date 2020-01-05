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

int main()
{
    int N;
    cin >> N;
    vector <vector <int> > v(N);
    REP(i, N)
    {
        int q;
        cin >> q;
        REP(j, q)
        {
            int t;
            cin >> t;
            v[i].push_back(t);
        }
        sort(v[i].begin(), v[i].end());
    }
    
    //全体の作れる組み合わせから、引いたほうがよい?

    return 0;
}