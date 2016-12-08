#ifndef __EXCEPTION
#define __EXCEPTION

#include <iostream>
#include <string>

using namespace std;

class Exception {
    string message;

    public :
        //Constructors
        Exception();
        Exception(const string);

        //Getters and setters
        string getMessage() const;
        void setMessage(string);
};

/*namespace exMessages {
    string INVALID_SIZE = "La taille des matrices n'est pas compatible. \n";
    string NON_SQUARE_MATRIX_INV = "Cette matrice ne peut etre inversée car elle n'est pas carrée. \n";
    string NON_INV_MATRIX = "Cette matrice n'est pas inversible. \n";
    string INDEX_OUT_OF_BOUND = "Débordement d'indice ou indices inferieurs a zéro. \n";
}*/

#endif
