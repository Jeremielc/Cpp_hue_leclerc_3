#include "../include/Exception.h"

using namespace std;

Exception::Exception() {
    message = "";
}

Exception::Exception(const string message) {
    this->message = message;
}

string Exception::getMessage() const {
    return message;
}

void Exception::setMessage(string message) {
    this->message = message;
}
