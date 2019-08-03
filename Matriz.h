#include<iostream>
#include<stdexcept>
#include<bits/stdc++.h>

using namespace std;

#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz{

	private:
		int n_rows, n_cols;
		double **m;

	public:

		Matriz(const int n_rows_=0, const int n_cols_=0);
		Matriz(const Matriz &A);
		Matriz(const int n_rows_, const int n_cols_, const double &fill);
		~Matriz();
		int getRows() const;
		int getCols() const;
		void zeros();
		void ones();
		void unit();

		Matriz operator + (const double &const_value);
		Matriz operator - (const double &const_value);
		Matriz operator * (const double &scalar);
		Matriz operator / (const double &scalar);
		Matriz &operator += (const double &scalar);
		Matriz &operator -= (const double &scalar);
		Matriz &operator *= (const double &scalar);
		Matriz &operator /= (const double &scalar);

		Matriz &operator = (const Matriz &B);
		Matriz operator + (const Matriz &B);
		Matriz operator - (const Matriz &B);
		Matriz operator * (const Matriz &B);
		Matriz &operator += (const Matriz &B);
		Matriz &operator *= (const Matriz &B);
		Matriz &operator -= (const Matriz &B); // RETORNA REFERENCIA PARA PODER FAZER CHAINING.

		bool operator == (const Matriz &B) const;
		bool operator != (const Matriz &B) const;
		Matriz &operator ~ ();
		double& operator () (const int &row, const int &col) const;
		friend ostream& operator << (ostream& os, const Matriz &B);
		friend istream& operator >> (istream& in, Matriz &B);
};
#endif
