#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <map>

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;


typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;

//人aは人bの「友達候補」であると定義します
//各人の友達候補の数

// unionfindのあとに友達の人数をへらす?
// ブロックは、isSameがtrueならへらす

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

    int size(int x)
    {
        return num[find(x)];
    }

};
int main()
{
    int N,M,K;
    cin >> N >> M >> K;

    vector <int> tomo(N, 0);
    vector <vector<int>> bro(N);

    UnionFind uf(N);

    //友達関係
    REP(i,M)
    {
        int a,b;
        cin >> a >> b;
        --a;--b;
        uf.unite(a, b);
        tomo[a]++;
        tomo[b]++;
    }

    //ブロック関係
    REP(i,K)
    {
        int c,d;
        cin >> c >> d;
        --c;--d;
        bro[c].push_back(d);
        bro[d].push_back(c);
    }

    REP(i, N)
    {
        int res;

        res = (uf.size(i)-1) - tomo[i];

        for(auto t:bro[i])
        {
            if(uf.same(i,t))--res;
        }
        
        if(res < 0)res = 0;
        
        
        //cout << uf.size(i) << ":";
        //cout << tomo[i] << ":";
        //cout << bro[i] << ":";

        cout << res << endl;
    }

    return 0;
}