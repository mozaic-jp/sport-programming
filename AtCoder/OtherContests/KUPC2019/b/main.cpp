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

int a[1555][1555];
int sum[1555][1555];

int area(int i0, int j0, int i1, int j1)
{
    return sum[i1][j1] - sum[i1][j0] - sum[i0][j1] + sum[i0][j0];
}

const int MOD = 1000000007;

class UnionFind 
{
public:
    int n;
    vector <int> par;//親
    vector <int> rank;//木の深さ
    vector <int> num;//要素数
    int g; //グループ数

    UnionFind(int _n)
    {
        n = _n;
        g = n;
        par.resize(n);
        rank.resize(n);
        num.resize(n);

        for(int i = 0; i < n; ++i)
        {
            par[i] = i; //自分自身を親に
            rank[i] = 0;
            num[i] = 1;
        }
    }


    //木の根を求める
    int find(int x)
    {
        if(par[x] == x)
        {
            return x;
        }
        else
        {
            return par[x] = find(par[x]);
        }
    }

    //xとyの属する集合を併合
    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);

        int numSum = num[x] + num[y];
        if(x == y)return;
        if(rank[x] < rank[y])
        {
            par[x] = y;
        }
        else
        {
            par[y] = x;
            if(rank[x] == rank[y])
            {
                //findしたあとの深さを変更で良い?
                rank[x]++;
            }
        }
        num[x] = num[y] = numSum;
        --g;
    }

    //xとyが同じ集合に属するか
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

};

vector<ll> weight, value;
ll dp[105][20050];

int main()
{
    int n,m,W;
    cin >> n >> m >> W;
    vector <int> w(n);
    vector <int> v(n);
    REP(i,n)
    {
        cin >> w[i] >> v[i];
    }

    UnionFind uf(n);

    REP(i,m)
    {
        int a,b;
        cin >> a >> b;
        --a;--b;
        uf.unite(a, b);
    }

    for(int i = 0; i < n; ++i)
    {
        //親となるもののみ
        if(uf.find(i) != i)continue;
        weight.push_back(0);
        value.push_back(0);
        for(int j = 0; j < n; ++j)
        {
            if(uf.same(i, j))
            {
                //末尾の配列に += 
                weight.back() += w[j];
                value.back() += v[j];
            }
        }
    }
    for(int i = 0; i < weight.size(); ++i)
    {
        for(ll j = 0; j <= W; ++j)
        {
            dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
            if(j + weight[i] <=  W)
            {
                dp[i+1][j + weight[i]] = max(dp[i][j], dp[i][j] + value[i]);
            }
        }
    }

    ll res = 0;
    //for(int i = 0; i <= W; ++i)
    //{
    //    res = max(res, dp[weight.size()][i]);
    //}

    res = dp[weight.size()][W];

    cout << res << endl;
    return 0;
}