// 112. ab-ba

// time limit per test: 0.25 sec.
// memory limit per test: 4096 KB


// You are given natural numbers a and b. Find ab-ba.


// Input

// Input contains numbers a and b (1≤a,b≤100).


// Output

// Write answer to output.


// Sample Input

// 2 3
// Sample Output

// -1

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    (a >= 1 && b <= 100)
        ? cout << pow(a, b) - pow(b, a) << endl
        : cout << -404 << endl;
    return 0;
}


// #include <iostream>
// #include <cmath> 
// using namespace std;

// int main() {
//     int a, b;
//     cin >> a >> b;
//     long long result = pow(a, b) - pow(b, a);
//     cout << result << endl;
//     return 0;
// }
