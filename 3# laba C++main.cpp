#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <stdexcept>

using namespace std;

// Класс Имя
class Name {
private:
    string lastName;
    string firstName;
    string middleName;

public:
    // Конструкторы
    Name(string first) : firstName(first) {}
    Name(string first, string last) : firstName(first), lastName(last) {}
    Name(string first, string last, string middle) : firstName(first), lastName(last), middleName(middle) {}

    string toString() const {
        stringstream ss;
        if (!lastName.empty()) ss << lastName << " ";
        if (!firstName.empty()) ss << firstName << " ";
        if (!middleName.empty()) ss << middleName;
        return ss.str();
    }

    void print() const {
        cout << toString() << endl;
    }

    // Методы для изменения имени
    void setLastName(const string& last) { lastName = last; }
    void setFirstName(const string& first) { firstName = first; }
    void setMiddleName(const string& middle) { middleName = middle; }
};

// Класс Дом
class House {
private:
    int floors;

public:
    House(int f) : floors(f) {}

    string toString() const {
        string suffix = "этажами";
        if (floors % 10 == 1 && floors % 100 != 11) {
            suffix = "этажом";
        } 
        return "Дом с " + to_string(floors) + " " + suffix;
    }

    void print() const {
        cout << toString() << endl;
    }
};

// Класс Сотрудник
class Employee {
private:
    Name name;
    string departmentName;
    Employee* manager;
    vector<Employee*> colleagues;

public:
    Employee(Name n, string dept, Employee* mgr = nullptr)
        : name(n), departmentName(dept), manager(mgr) {
        if (mgr) {
            mgr->addColleague(this);
        }
    }

    void addColleague(Employee* colleague) {
        colleagues.push_back(colleague);
    }

    string getName() const {
        return name.toString();
    }

    string toString() const {
        stringstream ss;
        if (manager) {
            ss << name.toString() << " начальник отдела " << departmentName;
        } else {
            ss << name.toString() << " работает в отделе " << departmentName 
               << ", начальник которого " << (manager ? manager->name.toString() : "Козлов Пётр");
        }
        return ss.str();
    }

    void print() const {
        cout << toString() << endl;
    }

    void setManager(Employee* mgr) {
        manager = mgr;
    }

    vector<Employee*> getColleagues() const {
        return colleagues;
    }

    string getDepartmentName() const {
        return departmentName;
    }

    // Методы для изменения имени
    void setName(const Name& newName) {
        name = newName;
    }

    void setDepartmentName(const string& dept) {
        departmentName = dept;
    }
};

// Класс Дробь
class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

public:
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) throw invalid_argument("Denominator cannot be zero");
        simplify();
    }

    string toString() const {
        return to_string(numerator) + "/" + to_string(denominator);
    }

    Fraction sum(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Fraction minus(int value) const {
        return Fraction(numerator - value * denominator, denominator);
    }

    Fraction multiply(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction divide(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    void print() const {
        cout << toString() << endl;
    }
};

// Главное меню
void showMenu() {
    cout << "Выберите задачу:\n";
    cout << "1. Имена\n";
    cout << "2. Дом\n";
    cout << "3. Сотрудники и отделы\n";
    cout << "4. Дроби\n";
    cout << "0. Выход\n";
}

void editName(Name& name) {
    cout << "Редактирование имени:\n";
    string firstName, lastName, middleName;
    
    cout << "Введите новое личное имя (или оставьте пустым для сохранения текущего): ";
    cin.ignore();
    getline(cin, firstName);
    if (!firstName.empty()) name.setFirstName(firstName);
    
    cout << "Введите новую фамилию (или оставьте пустым для сохранения текущей): ";
    getline(cin, lastName);
    if (!lastName.empty()) name.setLastName(lastName);
    
    cout << "Введите новое отчество (или оставьте пустым для сохранения текущего): ";
    getline(cin, middleName);
    if (!middleName.empty()) name.setMiddleName(middleName);

    cout << "Имя успешно изменено на: ";
    name.print();
}

void editEmployee(Employee& employee) {
    cout << "Редактирование сотрудника:\n";
    Name newName("", "", "");

    string firstName, lastName, deptName;
    
    cout << "Введите новое личное имя (или оставьте пустым для сохранения текущего): ";
    cin.ignore();
    getline(cin, firstName);
    if (!firstName.empty()) newName.setFirstName(firstName);
    
    cout << "Введите новую фамилию (или оставьте пустым для сохранения текущей): ";
    getline(cin, lastName);
    if (!lastName.empty()) newName.setLastName(lastName);
    
    cout << "Введите новую должность (или оставьте пустым для сохранения текущей): ";
    getline(cin, deptName);
    if (!deptName.empty()) employee.setDepartmentName(deptName);

    if (!newName.toString().empty()) {
        employee.setName(newName);
    }

    cout << "Сотрудник успешно изменен на: ";
    employee.print();
}

int main() {
    int choice;

    vector<Name> names; // Вектор для хранения имен
    vector<Employee*> employees; // Вектор для хранения сотрудников

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int action;
                cout << "1. Добавить имя\n";
                cout << "2. Изменить имя\n";
                cin >> action;

                if (action == 1) {
                    string firstName, lastName, middleName;
                    cout << "Введите имя (Личное имя): ";
                    cin >> firstName;

                    cout << "Введите фамилию (или оставьте пустым): ";
                    cin.ignore();
                    getline(cin, lastName);

                    cout << "Введите отчество (или оставьте пустым): ";
                    getline(cin, middleName);

                    Name name(firstName, lastName, middleName);
                    names.push_back(name);
                    cout << "Имя добавлено: ";
                    name.print();
                } else if (action == 2) {
                    int index;
                    cout << "Введите индекс имени для изменения (0 - " << names.size() - 1 << "): ";
                    cin >> index;

                    if (index >= 0 && index < names.size()) {
                        editName(names[index]);
                    } else {
                        cout << "Некорректный индекс.\n";
                    }
                }
                break;
            }
            case 2: {
                int floors;
                cout << "Введите количество этажей дома: ";
                cin >> floors;

                House house(floors);
                cout << "Дом: ";
                house.print();
                break;
            }
            case 3: {
                string firstName, lastName, deptName;
                cout << "Введите название отдела: ";
                cin.ignore();
                getline(cin, deptName);

                cout << "Введите имя первого сотрудника (Личное имя): ";
                cin >> firstName;
                cout << "Введите фамилию первого сотрудника: ";
                cin >> lastName;
                Name emp1Name(firstName, lastName);
                Employee emp1(emp1Name, deptName);

                cout << "Введите имя второго сотрудника (Личное имя): ";
                cin >> firstName;
                cout << "Введите фамилию второго сотрудника: ";
                cin >> lastName;
                Name emp2Name(firstName, lastName);
                Employee emp2(emp2Name, deptName);

                cout << "Введите имя третьего сотрудника (Личное имя): ";
                cin >> firstName;
                cout << "Введите фамилию третьего сотрудника: ";
                cin >> lastName;
                Name emp3Name(firstName, lastName);
                Employee emp3(emp3Name, deptName);

                // Назначаем второго сотрудника начальником
                emp1.setManager(&emp2);

                cout << "Сотрудники:\n";
                emp1.print();
                emp2.print();
                emp3.print();
                break;
            }
            case 4: {
                int num1, den1, num2, den2;
                cout << "Введите числитель и знаменатель первой дроби: ";
                cin >> num1 >> den1;
                Fraction f1(num1, den1);

                cout << "Введите числитель и знаменатель второй дроби: ";
                cin >> num2 >> den2;
                Fraction f2(num2, den2);

                cout << "Введите числитель и знаменатель третьей дроби: ";
                cin >> num1 >> den1;
                Fraction f3(num1, den1);

                cout << "Примеры операций с дробями:\n";
                cout << f1.toString() << " * " << f2.toString() << " = " << f1.multiply(f2).toString() << endl;
                cout << f1.toString() << " + " << f2.toString() << " = " << f1.sum(f2).toString() << endl;
                cout << f1.toString() << " - 5 = " << f1.minus(5).toString() << endl;
                cout << f1.toString() << " / " << f3.toString() << " = " << f1.divide(f3).toString() << endl;
                break;
            }
            case 0:
                cout << "Выход.\n";
                break;
            default:
                cout << "Неверный ввод. Попробуйте снова.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
