#include <iostream>

using namespace std;

int triangle(int k, ...) {
	if (k < 3) { return 0; }
	int* pointr = &k;
	int valid_tris = 0;
	for (; (k - 2) != 0; k--) {
		int sides[] = { *pointr, *pointr + 1, *pointr + 2 };
		bool valid = true;

		for (int i = 0; i < 3; i++) {
			if (sides[(i) % 3] + sides[(i + 1) % 3] <= sides[(i + 2) % 3]) { valid = false; }
		}

		if (valid) { valid_tris++; }

		++pointr;
	}

	return valid_tris;
}

int main() {
	cout << "Valid triangles: " << triangle(3, 1, 4, 2) << endl;
	cout << "Valid triangles: " << triangle(9, 1, 4, 2, 5, 2, 8, 10, 12, 15) << endl;
	cout << "Valid triangles: " << triangle(11, 1, 4, 2, 5, 2, 14, 7, 2, 9, 1, 12) << endl;

	return 0;
}

/*
Tests:

Test 1: triangle(3,   1, 4, 2)
Valid triangles: 1

Test 2: triangle(9,   1, 4, 2, 5, 2, 8, 10, 12, 15)
Valid triangles: 4

Test 3: triangle(11,   1, 4, 2, 5, 2, 14, 7, 2, 9, 1, 12)
Valid triangles: 5
*/