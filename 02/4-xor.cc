#include <iostream>
using namespace std;

int main() {
    bool a, b;

    cout << "Tabella verità XOR" << endl;
    a = true; b = true;
    cout << ((!a && b) || (a && !b)) << endl;

    a = true; b = false;
    cout << ((!a && b) || (a && !b)) << endl;

    a = false; b = true;
    cout << ((!a && b) || (a && !b)) << endl;

    a = false; b = false;
    cout << ((!a && b) || (a && !b)) << endl;

    return 0;
}
