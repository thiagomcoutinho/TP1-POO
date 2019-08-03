#include <iostream>
#include "Matriz.h"
#include<stdexcept>
#include<bits/stdc++.h>

using namespace std;

int main(){
    
    Matriz K(2,2);
    cin >> K;      
    
    Matriz Y;
    cout << Y << endl;

    Matriz X(3,1), A(3,3), C(3,3);
    
    cout << X << endl;
    cout << A << endl;
    cout << C << endl;
    
    Matriz W = C;
    cout << W << endl;
    
    Matriz Z(A);
    cout << Z << endl;
    
    int n_linhas = A.getRows();
    int n_cols = A.getCols();
    cout << n_linhas << " " << n_cols << endl;
    
    Y.unit();
    cout << Y << endl;
    
    A(2,1)=10;      
    cout << A << endl;
    Y.zeros();  
    cout << Y << endl;
    C=A+A;  
    cout << C << endl;
    C-=A;             
    cout << C << endl;
    A=C-A;            
    cout << A << endl;
    A+=A;             
    cout << A << endl;
    A=~C;             
    cout << A << endl;
    X.ones();         
    cout << X << endl;
    X*=2;             
    cout << X << endl;
    C=A*X;            
    cout << C << endl;
    C*=X;             
    cout << C << endl;
    cout << (A == C) << endl;
    cout << (X != Y) << endl;
    
}
