#include <iostream>
#include "Windows.h"

using namespace std;

class Overcoat {
private:
    char* type;
    int cost;
public:
    Overcoat(const char* typeI, int costI) : type{ new char[strlen(typeI) + 1] }, cost{ costI } {
        strcpy_s(type, strlen(typeI) + 1, typeI);
    }

    bool operator==(Overcoat& object) {
        return strcmp(type, object.type) == 0;
    }

    Overcoat& operator=(const Overcoat& object) {
        if (this != &object) {
            delete[] type;
            type = new char[strlen(object.type) + 1];
            strcpy_s(type, strlen(object.type) + 1, object.type);
            cost = object.cost;
        }
        return *this;
    }

    bool operator>(const Overcoat& object) {
        return cost > object.cost;
    }

    ~Overcoat() {
        delete[] type;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Overcoat overcoat1("шуба", 600);
    Overcoat overcoat2("шуба", 800);
    if (overcoat1 == overcoat2) cout << "Yes" << endl;
    else cout << "No" << endl;
    Overcoat overcoat3 = overcoat1;
    if (overcoat3 > overcoat2) cout << ">" << endl;
    else cout << "<" << endl;
    return 0;
}