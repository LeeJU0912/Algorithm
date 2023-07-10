#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    time_t curTime;
    time(&curTime);

    struct tm gmTM;
    gmtime_r(&curTime, &gmTM);

    cout << 1900 + gmTM.tm_year << '\n';
    cout << gmTM.tm_mon + 1 << '\n';
    cout << gmTM.tm_mday << '\n';

    return 0;
}