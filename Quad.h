//
//  quad.h
//  A3
//
//  Created by Sadaf Najam on 2019-07-07.
//  Copyright � 2019 Sadaf Najam. All rights reserved.
//
#pragma once
#ifndef QUAD_H
#define QUAD_H
#include <iostream>
#include <cmath>
#include <array>
using std::ostream;
using std::istream;

class Quad {
private:
	std::array<long long int, 4> quadCol; //Standard C++ array container
public:
	Quad(int q1 = 0, int q2 = 1, int q3 = 0, int q4 = 1) {
		quadCol[0] = q1;
		quadCol[1] = q2;
		quadCol[2] = q3;
		quadCol[3] = q4;
		standardize();  //standardize() call to reduce and normalizze x
	};

	Quad(const Quad &) = default;   //default ctor
	friend Quad operator - (Quad &q); //- negation as friend
	friend ostream & operator << (ostream &in, const Quad &q); //<< opeartor as friend
	friend istream & operator >> (istream &out, Quad &q); //>> opeartor as friend
	friend bool operator == (const Quad &q1, const Quad &q2); //== opeartor as friend
	friend bool operator != (const Quad &q1, const Quad &q2); //!= opeartor as friend
	const int& operator [] (int) const; //[] opeartor subscript
	long long int& operator [] (int);
    
    //Compund assignment operator
	Quad& operator += (const Quad &q);
	Quad& operator -= (const Quad &q);
	Quad& operator *= (const Quad &q);
	Quad& operator /= (const Quad &q);
	Quad& operator += (const double &k);
	Quad& operator -= (const double &k);
	Quad& operator *= (const double &k);
	Quad& operator /= (const double &k);

    //unary operators as friend
	friend Quad operator + (const Quad &q1, const Quad &q2);
	friend Quad operator - (const Quad &q1, const Quad &q2);
	friend Quad operator * (const Quad &q1, const Quad &q2);
	friend Quad operator / (const Quad &q1, const Quad &q2);
	friend Quad operator + (const Quad &q, const double &k);
	friend Quad operator - (const Quad &q, const double &k);
	friend Quad operator * (const Quad &q, const double &k);
	friend Quad operator / (const Quad &q, const double &k);
	friend Quad operator + (const double &k, const Quad &q);
	friend Quad operator - (const double &k, const Quad &q);
	friend Quad operator * (const double &k, const Quad &q);
	friend Quad operator / (const double &k, const Quad &q);
	Quad operator + () const;
	Quad operator - () const;
	Quad& operator ++ ();
	Quad& operator -- ();
	Quad operator ++ (int);
	Quad operator -- (int);

	double operator()();
    bool isSimilar(const Quad &q) const; //returns true if x is similar to y; false, otheriwse
    void reduce(); //reduces x; returns void
	double norm(); //returns the norm of x, a doauble value
	double absoluteValue(); //returns the absolute value of x, a double value
    void normalize(); // normalizes x; returns void
	Quad inverse() const; //returns the inverse of x
	Quad conjugate(); //returns the conjugate of x
    void standardize(); //both reduces and normalizes x; returns void
	friend Quad operator ^ (const Quad &, int); //XOR operator as friend
};
#endif
