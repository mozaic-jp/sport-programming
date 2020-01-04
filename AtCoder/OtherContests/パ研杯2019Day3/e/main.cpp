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


int main() {
    int H, W;
    cin >> H >> W;
    REP(i, H)
    {
        REP(j, W)
        {
            char c;
            cin >> c;
            a[i][j] = c == '#';
        }
    }


    //横のマスが 1,2,3,4,5になってく
    for(int i = 1; i <= H; ++i)
    {
        for(int j = 0; j < W; ++j)
        {
            //座標圧縮
            sum[i][j + 1] = sum[i][j] + a[i - 1][j];
        }
    }

    //横のマスが 2,4,6,8,10
    //横のマスが 4,8,12,16,20
    
    //横のマスが 2,4,6,1,2
    //横のマスが 4,8,12,2,4

    for(int i = 0; i < H; ++i)
    {
        for(int j = 0; j < W + 1; ++j)
        {
            //最大
            sum[i + 1][j] += sum[i][j];
        }
    }

    vector < vector < pair < pii , pii > > >  len2p(min(H,W) + 1);
    REP(i,H)
    {
        REP(j, W)
        {
            int ok = 0;
            //最小は2に
            int ng = min(H - i, W - j + 1);
            while(ok + 1 < ng)
            {
                int mid = (ok + ng) / 2;
                //右側、下側のみ探索
                //sumの作成手順的に、+側の方が値が大きいはず
                if(area(i , j, i + mid + 1, j + mid) > 0)ng = mid;
                else ok = mid;
            }
            //座標(i, j)から(i+1, j)へは[ok]で移動できますよと
            len2p[ok].emplace_back(pii(i,j), pii(i+1,j));

            
            ok = 0;
            ng = min(H - i + 1, W - j);
            while(ok + 1 < ng)
            {
                int mid = (ok + ng) / 2;
                if(area(i, j, i + mid, j + mid + 1) > 0)ng = mid;
                else ok = mid;
            }
            len2p[ok].emplace_back(pii(i,j), pii(i,j + 1));
        }
    }

    int q;
    cin >> q;
    vector <pair <pii, pii> > liyx(q);
    for(int i = 0; i < q; ++i)
    {
        cin >> liyx[i].second.first >> liyx[i].second.second >> liyx[i].first.first;
        liyx[i].second.first--;
        liyx[i].second.second--;
        liyx[i].first.second = i;
    }

    sort(liyx.begin(), liyx.end());
    reverse(liyx.begin(), liyx.end());

    UnionFind uf(H * W);

    // Wマス分increment
    auto p2u = [&](pii yx)
    {
        return yx.first * W + yx.second;
    };

    int l = len2p.size() - 1;

    vector <int> res(q);
    for(int i = 0; i < q; ++i)
    {
        int idx = liyx[i].first.second;
        //これfor文の中にある意味ある? 最小の liyx[i].first.firstでとまる?
        //たしかにliyxは降順ソートしてる
        while(l >= liyx[i].first.first)
        {
            for(int j = 0; j < len2p[l].size(); ++j)
            {
                //サイズl
                pii yx1 = len2p[l][j].first;
                pii yx2 = len2p[l][j].second;
                int u1 = p2u(yx1);
                int u2 = p2u(yx2);
                //合成
                uf.unite(u1, u2);
            }
            --l;
        }
        //開始座標
        pii yx = liyx[i].second;
        int u = p2u(yx);
        res[idx] = uf.num[uf.find(u)];
    }

    for(int i = 0; i < q; ++i)
    {
        cout << res[i] << endl;
    }
    return 0;
}

