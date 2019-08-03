#include"Matriz.h"
#include<iostream>
#include<stdexcept>
#include<bits/stdc++.h>

// PUBLIC METHODS
Matriz::Matriz(const int n_rows_, const int n_cols_){

	n_rows = n_rows_;
	n_cols = n_cols_;

	if(n_rows != 0 && n_cols != 0){

		m = new double*[n_rows];
		for(int i=0; i<n_rows; i++){
			m[i] = new double[n_cols];
		}
	}
}

Matriz::Matriz(const Matriz &A){

	n_rows = A.getRows();
	n_cols = A.getCols();

	if(n_rows != 0 && n_cols != 0){

		m = new double*[n_rows];
		for(int i=0; i<n_rows; i++){
			m[i] = new double[n_cols];
			for(int j=0; j<n_cols; j++){
				m[i][j] = A.m[i][j];
			}
		}
	}
}

Matriz::Matriz(const int n_rows_, const int n_cols_, const double &fill){

	n_rows = n_rows_;
	n_cols = n_cols_;

	if(n_rows != 0 && n_cols != 0){

		m = new double*[n_rows];
		for(int i=0; i<n_rows; i++){
			m[i] = new double[n_cols];
			for(int j=0; j<n_cols; j++){
				m[i][j] = fill;
			}
		}
	}
}

Matriz::~Matriz(){
    
    if(n_rows > 0){
        for (int i=0; i < n_rows; i++){
            delete [] m[i];
        }
        delete [] m;
    }

	n_rows = 0;
	n_cols = 0;
}

inline int Matriz::getRows() const{
	return(n_rows);
}

inline int Matriz::getCols() const{
	return(n_cols);
}

void Matriz::zeros(){
	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			m[i][j] = 0;
		}
	}
}

void Matriz::ones(){
	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			m[i][j] = 1;
		}
	}
}

void Matriz::unit(){
	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			if(i==j){
				m[i][j] = 1;
			}else{
				m[i][j] = 0;
			}
		}
	}
}

Matriz Matriz::operator + (const double &const_value){

	Matriz C(n_rows, n_cols);

	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			C.m[i][j] = m[i][j] + const_value;
		}
	}
	return(C);
}

Matriz Matriz::operator - (const double &const_value){

	Matriz C(n_rows, n_cols);

	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			C.m[i][j] = m[i][j] - const_value;
		}
	}
	return(C);
}

Matriz Matriz::operator * (const double &scalar){

	Matriz C(n_rows, n_cols);

	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			C.m[i][j] = m[i][j] * scalar;
		}
	}
	return(C);
}

Matriz Matriz::operator / (const double &scalar){

	if(scalar == 0){
		throw invalid_argument( "Division by zero!" );
	}

	Matriz C(n_rows, n_cols);

	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			C.m[i][j] = m[i][j] / scalar;
		}
	}
	return(C);
}

Matriz & Matriz::operator += (const double &scalar){

	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			m[i][j] += scalar;
		}
	}
	return(*this);
}

Matriz & Matriz::operator -= (const double &scalar){

	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			m[i][j] -= scalar;
		}
	}
	return(*this);
}

Matriz & Matriz::operator *= (const double &scalar){

	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			m[i][j] *= scalar;
		}
	}
	return(*this);
}

Matriz & Matriz::operator /= (const double &scalar){

	if(scalar == 0){
		throw invalid_argument( "Division by zero!" );
		return(*this);
	}

	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			m[i][j] /= scalar;
		}
	}
	return(*this);
}

Matriz & Matriz::operator = (const Matriz &B){

	int nrows_b = B.getRows();
	int ncols_b = B.getCols();
	double **resize;

	resize = new double*[nrows_b];
	for(int i=0; i<nrows_b; i++){
		resize[i] = new double[ncols_b];
		for(int j=0; j<ncols_b; j++){
			resize[i][j] = B.m[i][j];
		}
	}

	for (int i=0; i < n_rows; i++){
		delete [] m[i];
	}
	delete [] m;

	n_rows = nrows_b;
	n_cols = ncols_b;

	m = resize;

	return(*this);
}

Matriz Matriz::operator + (const Matriz &B){

	int nrows_b = B.getRows();
	int ncols_b = B.getCols();

	Matriz C(n_rows, n_cols);

	if(nrows_b != n_rows || ncols_b != n_cols){
		Matriz Erro(0, 0);
		return(Erro);
	}

	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			C.m[i][j] = m[i][j] + B.m[i][j];
		}
	}

	return(C);
}

Matriz Matriz::operator - (const Matriz &B){

	int nrows_b = B.getRows();
	int ncols_b = B.getCols();

	Matriz C(n_rows, n_cols);

	if(nrows_b != n_rows || ncols_b != n_cols){
		Matriz Erro(0, 0);
		return(Erro);
	}

	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			C.m[i][j] = m[i][j] - B.m[i][j];
		}
	}

	return(C);
}

Matriz Matriz::operator * (const Matriz &B){

	const int n_rows_b = B.getRows();

	if(n_cols != n_rows_b){
		Matriz Erro(0, 0);

		return(Erro);
	}

	double sum;
	const int n_cols_b = B.getCols();

	Matriz C(n_rows, n_cols_b);

	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols_b; j++){
			sum = 0;
			for(int k=0; k<n_cols; k++){
				sum += m[i][k]*B.m[k][j];
			}
			C.m[i][j] = sum;
		}
	}
	return(C);
}

Matriz & Matriz::operator += (const Matriz &B){

	int nrows_b = B.getRows();
	int ncols_b = B.getCols();

	if(nrows_b != n_rows || ncols_b != n_cols){
		n_rows = 0;
		n_cols = 0;
		return(*this);
	}

	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			m[i][j] += B.m[i][j];
		}
	}

	return(*this);
}

Matriz & Matriz::operator *= (const Matriz &B){

	const int n_rows_b = B.getRows();
	const int n_cols_b = B.getCols();

	if(n_cols != n_rows_b){
		n_cols = 0;
		n_rows = 0;

		return(*this);
	}
	Matriz C = *this;

	double **resize;
	resize = new double*[n_rows_b];
	for(int i=0; i<n_rows_b; i++){
		resize[i] = new double[n_cols_b];
		for(int j=0; j<n_cols_b; j++){
			resize[i][j] = B.m[i][j];
		}
	}

	for (int i=0; i < n_rows; i++){
		delete [] m[i];
	}
	delete [] m;

	n_cols = n_cols_b;
	m = resize;

	double sum;
	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			sum = 0;
			for(int k=0; k<n_cols; k++){
				sum += C.m[i][k]*B.m[k][j];
			}
			m[i][j] = sum;
		}
	}
	return(*this);
}

Matriz & Matriz::operator -= (const Matriz &B){

	int nrows_b = B.getRows();
	int ncols_b = B.getCols();

	Matriz C(nrows_b, ncols_b);

	if(nrows_b != n_rows || ncols_b != n_cols){
		n_cols = 0;
		n_rows = 0;
		return(*this);
	}

	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			m[i][j] -= B.m[i][j];
		}
	}

	return(*this);
}

bool Matriz::operator == (const Matriz &B) const{

	bool equals = true;

	const int nrows_b = B.getRows();
	const int ncols_b = B.getCols();

	if(nrows_b != n_rows || ncols_b != n_cols){
		return(false);
	}

	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			if(m[i][j] != B.m[i][j]){
				equals=false;
				break;
			}
		}
		if(!equals){
			return(false);
		}
	}

	return(equals);
}

bool Matriz::operator != (const Matriz &B) const{

	bool equals = true;

	const int nrows_b = B.getRows();
	const int ncols_b = B.getCols();

	if(nrows_b != n_rows || ncols_b != n_cols){
		return(true);
	}

	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			if(m[i][j] != B.m[i][j]){
				equals=false;
				break;
			}
		}
		if(!equals){
			return(true);
		}
	}

	return(!equals);
}

Matriz & Matriz::operator ~ (){

	double **resize;

	resize = new double*[n_rows];
	for(int i=0; i<n_rows; i++){
		resize[i] = new double[n_cols];
	}
	for(int i=0; i<n_rows; i++){
		for(int j=0; j<n_cols; j++){
			resize[j][i] = m[i][j];
		}
	}

	for (int i=0; i < n_rows; i++){
		delete [] m[i];
	}
	delete [] m;

	swap(n_rows, n_cols);
	m = resize;

	return(*this);
}

double& Matriz::operator () (const int &row, const int &col) const{
	return(m[row-1][col-1]);
}

ostream& operator << (ostream& os, const Matriz &B){

	const int nrows_b = B.getRows();
	const int ncols_b = B.getCols();

	for(int i=0; i<nrows_b; i++){
		for(int j=0; j<ncols_b; j++){
			os << B.m[i][j];
			os << "\t";
		}
		os << endl;
	}
	return(os);
}

istream& operator >> (istream &in, Matriz &B){

	const int nrows_b = B.getRows();
	const int ncols_b = B.getCols();

	for(int i=0; i<nrows_b; i++){
		for(int j=0; j<ncols_b; j++){
			in >> B.m[i][j];
		}
	}
	return(in);
}
