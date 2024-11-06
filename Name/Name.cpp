#include "Name.h"

Name::Name(string first) : firstName(first) {}
Name::Name(string first, string last) : firstName(first), lastName(last) {}
Name::Name(string first, string last, string middle) : firstName(first), lastName(last), middleName(middle) {}

string Name::toString() const {
    stringstream ss;
    if (!lastName.empty()) ss << lastName << " ";
    if (!firstName.empty()) ss << firstName << " ";
    if (!middleName.empty()) ss << middleName;
    return ss.str();
}

void Name::print() const {
    cout << toString() << endl;
}

void Name::setLastName(const string& last) { lastName = last; }
void Name::setFirstName(const string& first) { firstName = first; }
void Name::setMiddleName(const string& middle) { middleName = middle; }
