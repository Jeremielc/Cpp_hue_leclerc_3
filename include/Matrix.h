#ifndef __MATRIX
#define __MATRIX

#include <iostream>
#include <string.h>
#include "../include/Exception.h"

using namespace std;

class Matrix {
    int rows, columns;
    double** matrix;

    public :
        //Constructors
        Matrix();
        Matrix(int rows, int columns);
        Matrix(const Matrix&);

        //Destructors
        ~Matrix();

        void    allocate();
        Matrix  transpose();

        //Getters and setters
        int         getColumns() const;
        int         getRows() const;
        double**    getMatrix() const;
        void        setColumns(int columns);
        void        setRows(int rows);
        void        setMatrix(int rows, int columns, double** matrix);

        //Operators
        Matrix  operator = (const Matrix&);
        Matrix  operator + (Matrix&);
        Matrix  operator - (Matrix&);
        double* operator [] (int);
        double  operator () (const int, const int);

        //Friends
        friend Matrix       operator + (Matrix&, Matrix&);
        friend Matrix       operator - (Matrix&, Matrix&);
        friend ostream&     operator << (ostream&, Matrix&);
        friend istream&     operator >> (istream&, Matrix&);

    private :
        void freeMatrix();
};

#endif
