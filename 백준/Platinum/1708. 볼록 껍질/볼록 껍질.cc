#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

struct Point {
    int x, y; // 절대 좌표
    int p, q; // 0번 점에 대한 상대 좌표
    Point(): Point(0, 0, 1, 0){}
    Point(int x1, int y1) : Point(x1, y1, 1, 0){}
    Point(int x1, int y1, int p1, int q1): x(x1), y(y1), p(p1), q(q1){}

    // Point의 p, q 값에 대해 정렬 함수를 사용할 때 쓰이는 관계 연산자
    bool operator < (const Point& O) const {
        if (1LL * q * O.p != 1LL * p * O.q) {
            return 1LL * q * O.p < 1LL * p * O.q;
        }
        if (y != O.y) return y < O.y;
        return x < O.x;
    }
};

// AB와 AC 선분의 교차 확인.
long long ccw(const Point& A, const Point& B, const Point& C) {
    return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (B.y - A.y) * (C.x - A.x);
}

int main() {
    FastIO

    Point save[100000];

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        save[i] = Point(a, b);
    }

    // 점들을 y좌표 정렬 후 x좌표 정렬
    sort(save, save + N);

    // 0번 점을 기준으로 나머지 점들의 상대적인 거리를 저장.
    for (int i = 1; i < N; i++) {
        save[i].p = save[i].x - save[0].x;
        save[i].q = save[i].y - save[0].y;
    }

    sort(save + 1, save + N);

    // 스택 처음에 점 2개 넣음
    stack<int> s;
    s.push(0);
    s.push(1);

    int next = 2;

    // 모든 점에 대하여 비교해 나간다.
    while(next < N) { // N개를 다 훑을 떄까지
        while(s. size() >= 2) {
            int first, second;
            first = s.top(); // 이전의 점
            s.pop();
            second = s.top(); // 지금의 점

            // ccw 일 경우('이전-현재' 점의 선분에 대해 '현재-다음' 점의 선분이 왼쪽으로 꺾일 경우)
            if (ccw(save[second], save[first], save[next]) > 0) {
                s.push(first); // pop된 이전 점의 위치를 다시 넣는다.
                break;
            }
        }
        s.push(next);
        next++;
    }

    cout << s.size();

    return 0;
}