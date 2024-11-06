#include "Employee.h"

Employee::Employee(Name n, string dept, Employee* mgr) 
    : name(n), departmentName(dept), manager(mgr) {
    if (mgr) {
        mgr->addColleague(this);
    }
}

void Employee::addColleague(Employee* colleague) {
    colleagues.push_back(colleague);
}

string Employee::getName() const {
    return name.toString();
}

string Employee::toString() const {
    stringstream ss;
    if (manager) {
        ss << name.toString() << " начальник отдела " << departmentName;
    } else {
        ss << name.toString() << " работает в отделе " << departmentName 
           << ", начальник которого " << (manager ? manager->name.toString() : "Козлов Пётр");
    }
    return ss.str();
}

void Employee::print() const {
    cout << toString() << endl;
}

void Employee::setManager(Employee* mgr) {
    manager = mgr;
}

vector<Employee*> Employee::getColleagues() const {
    return colleagues;
}

string Employee::getDepartmentName() const {
    return departmentName;
}

void Employee::setName(const Name& newName) {
    name = newName;
}

void Employee::setDepartmentName(const string& dept) {
    departmentName = dept;
}
