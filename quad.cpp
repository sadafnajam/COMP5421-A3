//
//  quad.cpp
//  A3
//
//  Created by Sadaf Najam on 2019-07-07.
//  Copyright � 2019 Sadaf Najam. All rights reserved.
//

#include "Quad.h"
using std::invalid_argument;
using std::overflow_error;
using std::cout;
using std::endl;

//operator >> overloading and handling inputs
istream & operator >> (istream &in, Quad &q) {
	cout << "About to create the quad [a, b, c, d] \n";
	cout << "Enter four numbers a, b, c, d, in that order:" << endl;
	int count = 1;
	while (count < 5) {
		in >> q[count];
		count++;
	}
	return in;
}

//operator << overloading and handling outputs
ostream & operator << (ostream &out, const Quad &q) {
	out << "[" << q[1];
	out << ", " << q[2];
	out << ", " << q[3];
	out << ", " << q[4] << "]" << endl;
	return out;
}

//operator - overloading for negation returning quad
Quad operator - (Quad &q) {
	Quad negation(-q[1], q[2], -q[3], q[4]);
	negation.standardize();
	return negation;
}

//operator == overloading returning boolean
bool operator == (const Quad &q1, const Quad &q2) {
	return (q1[1] == q2[1] && q1[2] == q2[2] &&
		q1[3] == q2[3] && q1[4] == q2[4]);
}

//operator != overloading returning boolean
bool operator != (const Quad &q1, const Quad &q2) {
	return !(q1 == q2);
}

//Subscript operator [] overloading throws index out of bound
const int& Quad::operator [] (int i) const {
	if (i < 1 || i >= 5) {
		throw invalid_argument("index out of bounds");
	}
	return quadCol[i - 1];
}

//Subscript operator [] overloading throws index out of bound
long long int& Quad::operator [] (int i) {
	if (i < 1 || i >= 5) {
		throw invalid_argument("index out of bounds");
	}
	return quadCol[i - 1];
}

//compound assignment opeartor += overloading
Quad& Quad::operator += (const Quad &q) {
	int x1 = quadCol[0], x2 = quadCol[1], x3 = quadCol[2], x4 = quadCol[3];
	int y1 = q[1], y2 = q[2], y3 = q[3], y4 = q[4];
	quadCol[0] = (x1 * y2) + (x2 * y1);
	quadCol[1] = x2 * y2;
	quadCol[2] = (x3 * y4) + (x4 * y3);
	quadCol[3] = x4 * y4;
	this->standardize();
	return *this;
}

//compound assignment opeartor +- overloading
Quad& Quad::operator -= (const Quad &q) {
	int x1 = quadCol[0], x2 = quadCol[1], x3 = quadCol[2], x4 = quadCol[3];
	int y1 = q[1], y2 = q[2], y3 = q[3], y4 = q[4];
	quadCol[0] = (x1 * y2) - (x2 * y1);
	quadCol[1] = x2 * y2;
	quadCol[2] = (x3 * y4) - (x4 * y3);
	quadCol[3] = x4 * y4;
	this->standardize();
	return *this;
}

//compound assignment opeartor *= overloading
Quad& Quad::operator *= (const Quad &q) {
	int x1 = quadCol[0], x2 = quadCol[1], x3 = quadCol[2], x4 = quadCol[3];
	int y1 = q[1], y2 = q[2], y3 = q[3], y4 = q[4];
	quadCol[0] = (x1 * y1) * (x4 * y4) + 2 * (x3 * y3) * (x2 * y2);
	quadCol[1] = (x2 * y2) * (x4 * y4);
	quadCol[2] = ((x1 * y3) * (y2 * x4)) + ((y1 * x3) * (x2 * y4));
	quadCol[3] = (x2 * y2) * (x4 * y4);
	this->standardize();
	return *this;
}

//compound assignment opeartor /= overloading
Quad& Quad::operator /= (const Quad &q) {
	Quad inVal = q.inverse();
	quadCol[0] = inVal[1];
	quadCol[1] = inVal[2];
	quadCol[2] = inVal[3];
	quadCol[3] = inVal[4];
	this->standardize();
	return *this;
}

//compound assignment opeartor += overloading with double argument
Quad& Quad::operator += (const double &k) {
	quadCol[0] += k * quadCol[1];
	this->standardize();
	return *this;
}

//compound assignment opeartor -= overloading with double argument
Quad& Quad::operator -= (const double &k) {
	quadCol[0] -= k * quadCol[1];
	this->standardize();
	return *this;
}

//compound assignment opeartor *= overloading with double argument
Quad& Quad::operator *= (const double &k) {
	quadCol[0] *= k;
	quadCol[2] *= k;
	this->standardize();
	return *this;
}

//compound assignment opeartor /= overloading with double argument
Quad& Quad::operator /= (const double &k) {
	quadCol[1] *= k;
	quadCol[3] *= k;
	this->standardize();
	return *this;
}

//+ operator overloading with two quad argument
Quad operator + (const Quad &q1, const Quad &q2) {
	Quad garbag(q1);
	garbag += q2;
	garbag.standardize();
	return garbag;
}

//- operator overloading with two quad argument
Quad operator - (const Quad &q1, const Quad &q2) {
	Quad garbag(q1);
	garbag -= q2;
	garbag.standardize();
	return garbag;
}

//* operator overloading with two quad argument
Quad operator * (const Quad &q1, const Quad &q2) {
	Quad garbag(q1);
	garbag *= q2;
	garbag.standardize();
	return garbag;
}

/// operator overloading with two quad argument
Quad operator / (const Quad &q1, const Quad &q2) {
	Quad garbag(q1);
	garbag /= q2;
	garbag.standardize();
	return garbag;
}

//+ operator overloading with quad and double argument
Quad operator + (const Quad &q, const double &k) {
	Quad garbag(q);
	garbag += k;
	garbag.standardize();
	return garbag;
}

//- operator overloading with quad and double argument
Quad operator - (const Quad &q, const double &k) {
	Quad garbag(q);
	garbag -= k;
	garbag.standardize();
	return garbag;
}

//* operator overloading with quad and double argument
Quad operator * (const Quad &q, const double &k) {
	Quad garbag(q);
	garbag *= k;
	garbag.standardize();
	return garbag;
}

/// operator overloading with quad and double argument
Quad operator / (const Quad &q, const double &k) {
	Quad garbag(q);
	garbag /= k;
	garbag.standardize();
	return garbag;
}


Quad operator + (const double &k, const Quad &q) {
	return q + k;
}
Quad operator - (const double &k, const Quad &q) {
	return q - k;
}
Quad operator * (const double &k, const Quad &q) {
	Quad garbag(q);
	garbag *= k;
	garbag.standardize();
	return garbag;
}
Quad operator / (const double &k, const Quad &q) {
	Quad garbag(q);
	return (k * garbag.inverse());
}
Quad Quad::operator + () const {
	return *this;
}
Quad Quad::operator - () const {
	Quad garbag(*this);
	garbag *= -1;
	return garbag;
}
Quad& Quad::operator ++ () {
	*this += 1;
	return *this;
}
Quad& Quad::operator -- () {
	*this -= 1;
	return *this;
}
Quad Quad::operator ++ (int) {
	Quad garbag(*this);
	*this += 1;
	return garbag;
}
Quad Quad::operator -- (int) {
	Quad garbag(*this);
	*this -= 1;
	return garbag;
}

//Calculation of hcm
int hcm(int val1, int val2) {
	if (val2 == 0)
		return val1;
	return hcm(val2, val1 % val2);
}

//IsSimilar method implementation
bool Quad::isSimilar(const Quad &q) const {
	return (quadCol[0] * q[2] == q[1] * quadCol[1] && quadCol[2] * q[4] == q[3] * quadCol[3]);
}

//Inverse method implementation
Quad Quad::inverse() const {
	int q1 = quadCol[0], q2 = quadCol[1], q3 = quadCol[2], q4 = quadCol[3];
	Quad garbag;
	garbag[1] = q1 * q2 * (q4 * q4);
	garbag[2] = (q1 * q1) * (q4 * q4) - 2 * (q2 * q2 * (q3 * q3));
	garbag[3] = -(q2 * q2) * q3 * q4;
	garbag[4] = (q1 * q1) * (q4 * q4) - 2 * (q2 * q2) * (q3 * q3);
	garbag.standardize();
	return garbag;
}

//norm method implementation
double Quad::norm() {
	return pow((double)quadCol[0] / quadCol[1], 2) + pow((double)quadCol[2] / quadCol[3], 2);
}
void Quad::normalize() {
	if (quadCol[1] < 0 || quadCol[3] < 0) {
		if (quadCol[1] < 0) {
			quadCol[0] = -quadCol[0];
			quadCol[1] = -quadCol[1];
		}
		if (quadCol[3] < 0) {
			quadCol[2] = -quadCol[2];
			quadCol[3] = -quadCol[3];
		}
	}
}

//reduce method implementation
void Quad::reduce() {
	int x1 = quadCol[0], x2 = quadCol[1], x3 = quadCol[2], x4 = quadCol[3], g1 = hcm(x1, x2), g2 = hcm(x3, x4);
	quadCol[0] = x1 / g1;
	quadCol[1] = x2 / g1;
	quadCol[2] = x3 / g2;
	quadCol[3] = x4 / g2;
	this->normalize();
}

//Conjugate method implementation
Quad Quad::conjugate() {
	quadCol[0] = quadCol[0];
	quadCol[1] = quadCol[1];
	quadCol[2] = -quadCol[2];
	quadCol[3] = quadCol[3];
	this->standardize();
	return *this;
}

//Standardize method implementation
void Quad::standardize() {
	reduce();
	normalize();
}

double Quad::operator()() {
	return this->absoluteValue();
}


double Quad::absoluteValue() {
	return sqrt(this->norm());
}

//XOR opeartor overloading
Quad operator ^ (const Quad &q, int p) {
	int i = 1;
	int count = p < 0 ? -p : p;
	p = p < 0 ? (p + 1 == 0 ? -1 : p + 1) : p;
	Quad temp1(q);
	Quad temp2(q);
	while (i < count) {
		temp1 = temp1 * temp2;
		i++;
	}
	if (p < 0) {
		return p / (temp1 * p);
	}
	return temp1;
}
