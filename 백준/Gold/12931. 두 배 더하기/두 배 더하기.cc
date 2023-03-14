#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> save(N);

    int multi = 0;
    int plus_1 = 0;

    for (int i = 0; i < N; i++) {
        int counter1 = 0;
        int counter2 = 0;

        cin >> save[i];

        while(save[i] > 0) {
            if (save[i] % 2 == 0) {
                counter1++;
                save[i] /= 2;
            }
            else {
                counter2++;
                save[i]--;
            }
        }

        multi = max(multi, counter1);
        plus_1 += counter2;
    }

    cout << multi + plus_1;
    
    return 0;
}