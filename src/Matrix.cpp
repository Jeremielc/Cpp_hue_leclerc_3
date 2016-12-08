#include "../include/Matrix.h"

using namespace std;

Matrix::Matrix() {
    this->rows = 0;
    this->columns = 0;
}

Matrix::Matrix(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
    allocate();
}

Matrix::Matrix(const Matrix& m) {
    this->rows = m.getRows();
    this->columns = m.getColumns();
    allocate();
}

Matrix::~Matrix() {
    freeMatrix();
}

void Matrix::allocate() {
    if (rows > 0 && columns > 0) {
        matrix = new double*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new double[columns];
        }
    } else {
        Exception ex = Exception("Débordement d'indice ou indices inferieurs a zéro. \n");
        cerr << ex.getMessage();
    }
}

Matrix Matrix::transpose() {
    Matrix r = Matrix(getColumns(), getRows());
    for (int i = 0; i < r.getRows(); i++) {
        for (int j = 0; j < r.getColumns(); j++) {
            r.matrix[i][j] = matrix[j][i];
        }
    }

    cout << r;
    return r;
}

//Getters and setters
int Matrix::getColumns() const {
    return columns;
}

int Matrix::getRows() const {
    return rows;
}

double** Matrix::getMatrix() const {
    return matrix;
}

void Matrix::setColumns(int columns) {
    if (columns >= 0) {
        this->columns = columns;
    } else {
        Exception ex = Exception("Débordement d'indice ou indices inferieurs a zéro. \n");
        cerr << ex.getMessage();
    }
}

void Matrix::setRows(int rows) {
    if (columns >= 0) {
        this->rows = rows;
    } else {
        Exception ex = Exception("Débordement d'indice ou indices inferieurs a zéro. \n");
        cerr << ex.getMessage();
    }
}

void Matrix::setMatrix(int rows, int columns, double** matrix) {
    if (rows > 0 && columns > 0) {
        freeMatrix();

        this->rows = rows;
        this->columns = columns;

        matrix = new double*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new double[columns];
        }

        this->matrix = matrix;
    } else {
        Exception ex = Exception("Débordement d'indice ou indices inferieurs a zéro. \n");
        cerr << ex.getMessage();
    }
}

//Operators
Matrix Matrix::operator = (const Matrix& m) {
    Matrix r = Matrix();
    r.setRows(m.getRows());
    r.setColumns(m.getColumns());
    r.allocate();
    memcpy(r.getMatrix(), m.getMatrix(), m.getRows() * m.getColumns() * sizeof(double));

    return r;
}

Matrix Matrix::operator + (Matrix& m) {
    if (rows == columns && rows > 0 && columns > 0) {
        Matrix r = Matrix(m.getRows(), m.getColumns());
        for (int i = 0; i < m.getRows(); i++) {
            for (int j = 0; j < m.getColumns(); j++) {
                r[i][j] = this->matrix[i][j] + m[i][j];
            }
        }

        return r;
    } else {
        Exception ex = Exception("La taille des matrices n'est pas compatible. \n");
        cerr << ex.getMessage();
        return Matrix(-1, -1);
    }
}

Matrix Matrix::operator - (Matrix& m) {
    if (rows == columns && rows > 0 && columns > 0) {
        Matrix r = Matrix(m.getRows(), m.getColumns());
        for (int i = 0; i < m.getRows(); i++) {
            for (int j = 0; j < m.getColumns(); j++) {
                r[i][j] = this->matrix[i][j] - m[i][j];
            }
        }

        return r;
    } else {
        Exception ex = Exception("La taille des matrices n'est pas compatible. \n");
        cerr << ex.getMessage();
        return Matrix(-1, -1);
    }
}

double* Matrix::operator [] (int i) {   //On expose ici la structure interne de notre objet. Danger !
    if (i >= 0) {
        return matrix[i];
    } else {
        Exception ex = Exception("Débordement d'indice ou indices inferieurs a zéro. \n");
        cerr << ex.getMessage();
        return NULL;
    }
}

double Matrix::operator () (const int i, const int j) {
    return matrix[i - 1][j - 1];
}

//Friends
Matrix operator + (Matrix& a, Matrix& b) {
    if (a.getRows() == a.getColumns() && b.getRows() == b.getColumns() && a.getRows() > 0 && a.getColumns() > 0) {
        Matrix r = Matrix(a.getRows(), a.getColumns());
        for (int i = 0; i < a.getRows(); i++) {
            for (int j = 0; j < a.getColumns(); j++) {
                r[i][j] = a[i][j] + b[i][j];
            }
        }

        return r;
    } else {
        Exception ex = Exception("La taille des matrices n'est pas compatible. \n");
        cerr << ex.getMessage();
        return Matrix(-1, -1);
    }
}

Matrix operator - (Matrix& a, Matrix& b) {
    if (a.getRows() == a.getColumns() && b.getRows() == b.getColumns() && a.getRows() > 0 && a.getColumns() > 0) {
        Matrix r = Matrix(a.getRows(), a.getColumns());
        for (int i = 0; i < a.getRows(); i++) {
            for (int j = 0; j < a.getColumns(); j++) {
                r[i][j] = a[i][j] - b[i][j];
            }
        }

        return r;
    } else {
        Exception ex = Exception("La taille des matrices n'est pas compatible. \n");
        cerr << ex.getMessage();
        return Matrix(-1, -1);
    }
}

ostream& operator << (ostream& s, Matrix& m) {
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getColumns(); j++) {
            s << m.matrix[i][j] << " ";
        }

        s << endl;
    }

    return s;
}

istream& operator >> (istream& s, Matrix& m) {
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getColumns(); j++) {
            cout << "[" << i + 1 << "][" << j + 1 << "] : ";
            cin >> m.matrix[i][j];
        }

        cout << endl;
    }

    return s;
}

void Matrix::freeMatrix() {
    for (int i = 0; i < rows; i++) {
        delete [] matrix[i];
    }

    delete [] matrix;
}
