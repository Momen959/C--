// 105. Div 3

// time limit per test: 0.25 sec.
// memory limit per test: 4096 KB


// There is sequence 1, 12, 123, 1234, ..., 12345678910, ... . Given first N elements of that sequence. You must determine amount of numbers in it that are divisible by 3.


// Input

// Input contains N (1<=N<=231 - 1).


// Output

// Write answer to the output.


// Sample Input

// 4
// Sample Output

// 2

#include <iostream>
using namespace std;
int main(){
    int n, counter = 0;
    cin >> n;
    for(int i = 0; i <= n; i++){
        if(i % 3 == 0)
            counter++;
    }
    cout << counter << endl;
    return 0;
}
