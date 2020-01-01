#include <iostream>

using namespace std;

/*********************************************
 * 多桁計算
 *********************************************/
#include <iostream>  // for cout
#include <stdio.h>   // for printf()

#define KETA 100  // 最大桁数
#define N    10   // 配列サイズ

using namespace std;

/*
 * 計算クラス
 */
class Calc
{
    // 各種変数
    int i;              // LOOP インデックス
    int carry, borrow;  // 繰り上がり、借り
    long w;             // 被乗数、被除数ワーク
    long remainder;     // 剰余ワーク
    int z[N];           // 計算結果保存用

    public:
        // 計算
        void calc();
        // ロング / ショート
        void ldiv(int *, int);
        // 結果出力（ロング用）
        void displayL(int *);
};

/*
 * 計算
 */
void Calc::calc()
{
    // 計算する数字（a, b: 加減算用、c, d: 剰除算用、z: 結果格納用）
    int a[N] = {56789012,34567890,12345678,90123456,78901234};
    int d    = 26;

    // ロング / long
    ldiv(a, d);
}
/*
 * ロング / ショート
 */
void Calc::ldiv(int c[], int d)
{
    // 計算
    remainder = 0;
    for (i = 0; i < N; i++) {
        w = c[i];
        z[i] = (w + remainder) / d;
        remainder = ((w + remainder) % d) * 100000000;
    }

    // 結果出力
    displayL(z);
    printf("\n");
}

/*
 * 結果出力（ロング用）
 */
void Calc::displayL(int s[])
{
    for (i = 0; i < N; i++)
        printf(" %08d", s[i]);
    printf("\n");
}

/*
 * メイン処理
 */
int main()
{
    try
    {
        // 計算クラスインスタンス化
        Calc objCalc;

        // 多桁計算
        objCalc.calc();
    }
    catch (...) {
        cout << "例外発生！" << endl;
        return -1;
    }

    // 正常終了
    return 0;
}
