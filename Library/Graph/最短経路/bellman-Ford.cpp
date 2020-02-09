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

const int MAX_E = 10000;
const int MAX_V = 10000;

struct edge
{
    int from, to, cost;
};

edge es[MAX_E]; //辺

int d[MAX_V];   //最短距離

int V,E;        //Vは頂点数、Eは辺数

void shortest_path(int s)
{
    for(int i = 0; i < V; ++i)
    {
        d[i] = INF;
    }
    d[s] = 0;
    while(true)
    {
        bool update = false;
        for(int i = 0; i < E; ++i)
        {
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost)
            {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
            if(!update) break;
        }

    }

}