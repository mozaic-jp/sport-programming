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

//行える操作: 整数 i ( 1 ≤ i ≤ N − 1 ) を一つ選ぶ。 
//左から i 番目のカードと i + 1 番目のカードの位置を入れ替え、さらにこれら 2 枚のカードを裏返す。

//可能性のある数列と移動回数が求められればよい

//奇数回の移動先ではbになる
//bの数は偶数個になる


int main(){

    int N;
    cin >> N;

    vector <int> guki; 
    vector <int> a(N); 
    vector <int> b(N); 
    REP(i, N)cin >> a[i];
    REP(i, N)cin >> b[i];
    int res = MOD;

    //奇数回の移動先ではbになる
    //010101
    //すべてa[i]の状態がうえとする
    //permutaitionでみたいので、0を寄せる

    for(int i = 0; i < N; i+=2)
    {
        guki.push_back(0);
    }
    for(int i = 1; i < N; i+=2)
    {
        guki.push_back(1);
    }

    //すべての順列を試す
    do
    {
        vector <pair <int, int> >  odd;
        vector <pair <int, int> >  even;
        //010
        for(int i = 0; i < N; ++i)
        {
            if(i % 2 == 1)
            {
                //元の位置が奇数
                if(guki[i] == 1)
                {
                    odd.push_back({a[i], i});
                }
                else
                {
                    even.push_back({b[i], i});
                }
            }
            else
            {
                if(guki[i] == 1)
                {
                    odd.push_back({b[i], i});
                }
                else
                {
                    even.push_back({a[i], i});
                }
            }
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        int las = 0;
        bool can = true;
        vector <int> pos;
        for(int i = 0; i < N; ++i)
        {
            int value;
            if(i % 2 == 1)
            {
                value = odd[i/2].first;
                pos.push_back(odd[i/2].second);
            }
            else
            {
                value = even[i/2].first;
                pos.push_back(even[i/2].second);
            }
            //偶数と整数の順序だけは変更できないので、単調増加か判定
            if(value < las)
            {
                can = false;
                break;
            }
            else
            {
                las = value;
            }
        }

        if(!can)continue;
        int cnt = 0;
        //転倒数を数え上げる
        for(int i = 0; i < N; ++i)
        {
            int cur = pos[i];
            for(int j = i + 1; j < N; ++j)
            {
                if(cur > pos[j])++cnt;
            }
        }

        res = min(res, cnt);

    } while (next_permutation(guki.begin(),guki.end()));
    
    if(res == MOD)res = -1;
    cout << res << endl;

    return 0;    
}
