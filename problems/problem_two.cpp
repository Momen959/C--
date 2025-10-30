//The Fibonacci sequence of numbers is known: F1 = 1; F2 = 1; Fn+1 = Fn + Fn-1, for n>1. You have to find S - the sum of the first K Fibonacci numbers.


// Input

// First line contains natural number K (0<K<41).


// Output

// First line should contain number S.


// Sample Input

// 5
// Sample Output

// 12

#include <iostream>
using namespace std;


int main(){
    int firstNumber = 1, secondNumber = 1, thirdNumber, k;
    cin >> k;
    for(int i = 0; i < k; i++){
        thirdNumber = firstNumber + secondNumber;
        firstNumber = secondNumber;
        secondNumber = thirdNumber;
    }
    cout << thirdNumber << endl;
}