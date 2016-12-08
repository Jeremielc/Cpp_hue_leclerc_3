#include "../include/Main.h"

using namespace std;

int main() {
    //Tests des constructeurs, initialisation et affichage
    cout << "Initialisation d'une matrice 3 par 3." << endl;
    cout << "Saisi des données : " << endl;
    Matrix m = Matrix(3, 3);
    cin >> m;

    cout << "Affichage de la matrice : " << endl;
    cout << m << endl;

    cout << "Transposition de la matrice précédente : " << endl;
    Matrix t = Matrix(m);
    t = m.transpose();
    //cout << t << endl;            //Problème sur le retour.

    /*Matrix a = Matrix(2, 2);
    Matrix b = Matrix(2, 2);
    cin >> a;
    cin >> b;

    Matrix c = Matrix(a);
    c = a + b;
    cout << c << endl;
    c = c - b;
    cout << c << endl;*/

    cout << endl;
    return 0;
}
