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

using namespace std;

int T;
int A[1001];
int B[1001];
vector<int> N;
vector<int> M;

unsigned long long answer;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        A[i] += A[i - 1]; // A 배열에 누적합 저장
        for (int j = 0; j < i; j++) {
            N.push_back(A[i] - A[j]); // 모든 부분 합 경우의 수 저장 > 무조건 연속된 값들의 합만 저장 가능
        }
    }

    cin >> n; // 똑같이 반복

    for (int i = 1; i <= n; i++) {
        cin >> B[i];
        B[i] += B[i - 1];
        for (int j = 0; j < i; j++) {
            M.push_back(B[i] - B[j]);
        }
    }

    sort(M.begin(), M.end()); // 모든 가능한 부분 합 정렬 > 이분 탐색을 위해서 정렬

    for (int i = 0; i < N.size(); i++) {
        int target = T - N[i]; // M 배열 안에서 target 값이 나오는 값들의 개수를 찾는다.
        answer += (upper_bound(M.begin(), M.end(), target) - lower_bound(M.begin(), M.end(), target));
        // target 초과 값이 있는 가장 낮은 인덱스 - target 이상의 값이 있는 가장 낮은 인덱스 = target 값이 있거나, target 값이 없다면 0이 나오게 된다.
    }

    cout << answer;

    return 0;
}