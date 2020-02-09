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
const int MAX_E = 10000;
const int MAX_V = 10000;

ll cost [MAX_V][MAX_V]; //cost[u][v] は辺e=(u,v)のコスト
ll d[MAX_V];            //頂点sからの頂点距離
bool used[MAX_V];       //すでに使われたかのフラグ
int V;                  //頂点数

//始点sから各頂点への最短距離を求める
void dijkstra(int s)
{
    fill(d, d + V, INF);
    fill(used, used + V, false);
    d[s] = 0;

    while(true)
    {
        //今回の対象
        int v = -1;
        //まだ使われていない頂点のうち距離が最小のものを探す
        for(int u = 0; u < V; ++u)
        {
            if(!used[u] && (v == -1 || d[u] < d[v]))
            {
                v = u;
            }
        }
        if(v == -1) break;
        used[v] = true;

        for(int u = 0; u < V; ++u)
        {
            d[u] = min(d[u], d[v] + cost[v][u]);
        }
    }



}