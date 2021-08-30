#include <bits/stdc++.h>
using namespace std;

int euclidsGCD(int a, int b) {                       // Long division to find out GCD/HCF
	int dividend = max(a, b);                        // Not required as Euclid's algorithm automatically swaps the smaller and larger
	int divisor = min(a, b);                         // 12 % 18 = 12 as remainder (which becomes new divisor) and 18 (divisor) becomes new dividend
	// if (dividend % divisor == 0)                  // Alternate base case: When remainder = 0, the prev. divisor becomes the GCD
	// 	return divisor;

	if (divisor == 0)                                // Base case: When divisor = 0 (which it becomes eventually), the dividend is the GCD
		return dividend;

	return euclidsGCD(divisor, dividend % divisor);  // The prev. divisor becomes new dividend, and remainder becomes the new divisor
}

int gcd(int a, int b) {                              // Works exactly like the code above since a and b interchangeable in Euclids algo
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

// Time complexity:-
// In the worst case, a and b are consecutive Fibonacci numbers
// Time complexity = O(log(min(a, b)))

int euclidsLCM(int a, int b) {                       // Works even for (0, x) since GCD = x and product = 0
	return (a * b) / euclidsGCD(a, b);               // GCD * LCM = a * b
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int testNum;
	cin >> testNum;
	while (testNum--) {
		int num1, num2;
		cin >> num1 >> num2;

		cout << "GCD(" << num1 << "," << num2 << "): " << euclidsGCD(num1, num2) << endl;
		cout << "gcd(" << num1 << "," << num2 << "): " << gcd(num1, num2) << endl;
		cout << "LCM(" << num1 << "," << num2 << "): " << euclidsLCM(num1, num2) << endl;
	}
	return 0;
}

// Testcases:-

// Inputs:

// 5
// 4 12
// 12 18
// 3 17
// 1 22
// 0 22

// Outputs:

// GCD(4,12): 4
// LCM(4,12): 12
// GCD(12,18): 6
// LCM(12,18): 36
// GCD(3,17): 1
// LCM(3,17): 51
// GCD(1,22): 1
// LCM(1,22): 22
// GCD(0,22): 22
// LCM(0,22): 0
