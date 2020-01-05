#include <iostream>
#include <fstream>
#include <algorithm>       // for next_permutation
#include <vector>
#include <queue>
#include <bits/stl_numeric.h>

#define DEBUG 0
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;


ll N, K;
int main() {

    cin >> N >> K;

    //種類が何個あるか
    vector <int> v[N];
    //ネタ
    vector <ll> t(N);
    //おいしさ
    vector <ll> d(N);
    vector <pii> p(N);
    REP(i,N)
    {
        cin >> t[i] >> d[i];
        --t[i];
        p.push_back(pii(d[i], t[i]));
    }
    //美味しさの順でソートする
    sort(p.begin(),p.end(), greater<pii>());

    ll res = 0;
    priority_queue <pii, vector<pii>, greater<pii> > que;
    ll cnt = 0;

    for(int i = 0; i < K; ++i)
    {
        if(v[p[i].second].size() == 0)
        {
            ++cnt;
        }
        else
        {
            //入れ替える可能性のあるものをqueに突っ込んどく(queは昇順ソートされている)
            que.push(p[i]);
        }
        res += p[i].first;
        v[p[i].second].push_back(p[i].first);
    } 

    res += (ll)cnt * cnt;
    ll out = res;
    int cur = K;
    for(; cur < N; ++cur)
    {
        if(que.empty())break;
        int idx = p[cur].second;
        if(v[idx].size() == 0)
        {
            pii top = que.top();
            que.pop();
            v[idx].push_back(p[cur].first);
            ++cnt;
            res += 2 * cnt - 1;
            res -= top.first;
            res += p[cur].first;
            //入れ替えて種類を増やしたときの値を求める
            out = max(res, out);
        }
    }


    cout << out << endl;
    return 0;
}
