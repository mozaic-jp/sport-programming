#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll INF = 1000000000000000000LL;
using namespace std;

const int MOD = 1000000007;

//http://potetisensei.hatenablog.com/entry/2018/05/04/225811

//グラフ問題
//LCA:Lowest Common Ancestor(最近共通祖先)
//w = lca(u, v)とすると
//Q(u, v) = Q(w, u) + Q(w, v) 
//        = Q(root, u) + Q(root, v) - 2*Q(root, w)

//mod 2しか見ないので、
// = Q(root, u) + Q(root, v)

//奇数のもののうち最も木の深さが深い頂点を取ってくると、
//その頂点とその頂点の一つ親の間の辺は、
//奇数回しか選ばれないので、偶数にすることは必ずできない。


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;//N頂点M個のクエリ
    cin >> N >> M;
    vector <int> g(N);

    REP(i,M)
    {
        int a,b;
        cin >> a >> b;
        --a;--b;
        ++g[a];
        ++g[b];
    }

    string res = "YES";

    REP(i,N)
    {
        if(g[i] % 2 == 1)
        {
            res = "NO";
            break;
        }
    }

    cout << res << endl;



    return 0;    
}
