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

Graph G;

int main()
{
    int N,M;
    cin >> N >> M;
    G.assign(N, vector<int>());
    REP(i,M)
    {
        int v,u;
        cin >> v >> u;
        --v;--u;
        G[v].push_back(u);
        //G[u].push_back(v);
    }

    int s, t;
    cin >> s >> t;
    --s;--t;

    vector <vector < ll > > d(N, vector<ll>(3, -1)); 
    d[s][0] = 0;

    queue<pair<int,int>> que;
    que.push({s,0});
    while(!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();

        int v = cur.first;
        int parity = cur.second;//(0,1,2)

        for(auto nv: G[v])
        {
            int np = (parity + 1) % 3;
            if(d[nv][np] == -1)
            {
                d[nv][np] = d[v][parity] + 1;
                que.push({nv,np});
            }
        }
    }


    int res;
    res = d[t][0] / 3;
    if(d[t][0] == -1)res = -1;

    cout << res << endl;


    return 0;
}