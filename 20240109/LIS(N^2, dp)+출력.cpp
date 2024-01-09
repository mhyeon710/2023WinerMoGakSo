//LIS(N^2) + 결과 출력
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int arr[1000], ans[1000], maxlen;
stack <int> s;
int main() {
    int N; cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    
    for (int i=0; i<N; i++) {
        for (int k=0; k<=i; k++) {
            if (arr[i] > arr[k]) {
                ans[i] = max(ans[i], ans[k]+1);
            }
        }
        if (ans[i] > maxlen) maxlen = ans[i];
    }
    cout << maxlen + 1 << '\n';

    s.push(1001);
    for (int i=N-1; i>=0; i--) {
        if (ans[i] == maxlen && arr[i] < s.top()) {
            s.push(arr[i]);
            maxlen--;
        }
    }
    
    while (s.size() > 1) {
        cout << s.top() << ' ';
        s.pop();
    }
    return 0;
}