#ifndef NAME_H
#define NAME_H

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Name {
private:
    string lastName;
    string firstName;
    string middleName;

public:
    Name(string first);
    Name(string first, string last);
    Name(string first, string last, string middle);
    string toString() const;
    void print() const;
    void setLastName(const string& last);
    void setFirstName(const string& first);
    void setMiddleName(const string& middle);
};

#endif // NAME_H
