#pragma once

class Calculations {
private:
	int integerPart;
	float floatPart;
public:
	void Init() {
		integerPart = 0;
		floatPart = 0.0;
	};
	void SetNumber(int n) {
		integerPart = n;
	};
	void SetNumber(float n) {
		floatPart = n;
	};
	double Multiply(double k) {
		return ((double)integerPart + (double)(floatPart - (int)floatPart)) * k;
	};
};
