#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <tuple>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <array>
#include <climits>
#include <cstdlib>
#include <utility>
#include <regex>
#include <numeric>
#include <cctype>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <typeinfo>
#include <cstdlib>
#include <unordered_map>
#include <cfloat>

using namespace std;

typedef vector<vector<long long>> matrix;

int D;

matrix A = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0}
};

matrix ans = {
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1}
};

matrix operator * (matrix &a, matrix &b) { // * matrix 와 matrix 사이에 * 연산자를 사용할 경우 다음 함수가 사용 된다.
    matrix c(8, vector<long long>(8)); // 8 x 8 영행렬 생성

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 1000000007;
        }
    }

    return c;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> D;

    while (D > 0) { // A행렬을 D번 곱하는 방법.
        if (D & 1) { // D가 홀수라면, 지금 A행렬을 곱해준다.
            ans = ans * A;
        }

        A = A * A; // A행렬을 제곱한다. (연산자 오버로딩)
        D = D >> 1; // D = D / 2
    }

    cout << ans[0][0];

    return 0;
}