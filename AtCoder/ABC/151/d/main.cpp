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

int d[20][20];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int H,W;
int iMax = 0;

int used[20][20];

int dfs(int x, int y, int cnt)
{
    iMax = max(iMax, cnt);
    if(used[x][y] == 1)return 0;
    used[x][y] = 1;
    if(d[x][y] == '#')return 0;

    for(int i = 0; i < 4 ; ++i)
    {
        int cur_x = x + dx[i];
        int cur_y = y + dy[i];
        if(cur_x < 0 || cur_x >= W || cur_y < 0 || cur_y >= H)continue;

        dfs(cur_x, cur_y, cnt + 1);
    }

    return 0;
}

void warshall_floyd(int n) {
  for (int k = 0; k < n; k++){       // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
      for (int j = 0; j < n; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    vector <string> s(H);
    REP(i, H)
    {
        cin >> s[i];
    }

    REP(i, H)
    {
        REP(j, W)
        {
            REP(y,20)
            {
                REP(x,20)
                {
                    used[y][x] = 0;
                }
            }
            int cnt;
            queue<pair < pair <int, int> , int > > que;
            pair <int, int> a = {i,j};
            que.push({a, 0});
            while (!que.empty()) {
                auto v = que.front(); // キューから先頭頂点を取り出す
                que.pop();
                int y = v.first.first;
                int x = v.first.second;
                cnt = v.second;
                
                iMax = max(iMax, cnt);
                if(s[y][x] == '#')continue;
                if(used[y][x] == 1)continue;
                used[y][x] = 1;

                for(int i = 0; i < 4 ; ++i)
                {
                    int cur_y = y + dy[i];
                    int cur_x = x + dx[i];
                    if(cur_x < 0 || cur_x >= W || cur_y < 0 || cur_y >= H)continue;
                    pair <int, int>  b =  {cur_y, cur_x};
                    que.push({b, cnt + 1});

                }

            }
        }
    }
    cout << iMax - 1<< endl;

    return 0;
}
