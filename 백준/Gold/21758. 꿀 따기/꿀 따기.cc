#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;
int bee1, bee2;
int house;

int ans;

int take(int start) {
    int hap = 0;
    if (start == house) {
        return save[start];
    }
    else if (start < house) {
        if (!(start == bee1 || start == bee2)) {
            hap += save[start];
        }
        hap += take(start + 1);
    }
    else {
        if (!(start == bee1 || start == bee2)) {
            hap += save[start];
        }
        hap += take(start - 1);
    }
    return hap;
}

int main() {
    FastIO

    cin >> N;

    save = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            for (int k = 0; k < N; k++) {
                if (k == i || k == j) continue;

                bee1 = i;
                bee2 = j;
                house = k;

                int temp = 0;

                temp += take(bee1);
                temp += take(bee2);

                ans = max(ans, temp);
            }
        }
    }

    cout << ans;

    return 0;
}