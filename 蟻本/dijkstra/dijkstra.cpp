#include <bits/stdc++.h> 

//p.96
//dijkstra
//最短単一経路問題
//開始点を固定して、
//開始点からの各点の最短経路を求めるプログラミング

//1. 最短距離が確定した頂点と隣接している頂点を更新する
//2. 1で使った「最短距離が確定した頂点」はもう使わない

//確定しているもの(負の辺がない場合)
//1回目は、開始点と隣接している最も短い辺
//開始点と隣接している最も短い辺
//次-> 確定した点と隣接している最も短い辺

static const int MAX_V = 100010;
static const int INF = 1000000007;

//cost[u][v]=辺e(u,v)のコスト(存在しない場合はINF)
int cost[MAX_V][MAX_V];
//頂点sからの最短距離
int d[MAX_V];
//すでに使われたかのフラグ
bool used[MAX_V];
//頂点数
int V;

void dijkstra(int s)
{
    fill(d, d+V,INF);
    fill(used,used+V,false);
    d[s] = 0;
    while(true)
    {
        int v = -1;
        //まだ使われていない頂点のうち距離が最小のものを探す
        for(int u = 0; u < V; ++u)
        {
            if(!used[u] && (v == -1 || d[u] < d[v]))
            {
                v = u;
            }
        }

        if(v == -1)break;//終わり

        used[v] = true;

        for(int u = 0; u < V; ++u)
        {
            d[u] = min(d[u], d[v] + cost[v][u]);
        }
    }
}

int main()
{
    int V;
    cin >> V;
    int s,g;//開始点、終了点
    cin >> s >> g;
    int E;
    cin >> E;//辺の数
    REP(i, E)
    {
        int v,u,c;
        cin >> v >> u >> c;
        --v;--u;
        cost[v][u] = c;
    }

    dijkstra(s);

    int res;

    res = d[g];

    return 0;
}