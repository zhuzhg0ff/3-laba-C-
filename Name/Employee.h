#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <vector>
#include <string>
#include "Name.h"

using namespace std;

class Employee {
private:
    Name name;
    string departmentName;
    Employee* manager;
    vector<Employee*> colleagues;

public:
    Employee(Name n, string dept, Employee* mgr = nullptr);
    void addColleague(Employee* colleague);
    string getName() const;
    string toString() const;
    void print() const;
    void setManager(Employee* mgr);
    vector<Employee*> getColleagues() const;
    string getDepartmentName() const;
    void setName(const Name& newName);
    void setDepartmentName(const string& dept);
};

#endif // EMPLOYEE_H
