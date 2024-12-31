#include <iostream>
using namespace std;

// Funktion zur Berechnung
void calculator() {
    char operation;
    double num1, num2;

    cout << "Willkommen beim Taschenrechner!\n";
    cout << "Bitte geben Sie die Berechnung in der Form: Zahl1 Operator Zahl2 ein.\n";
    cout << "Unterstützte Operatoren: +, -, *, /\n";

    cout << "Eingabe: ";
    cin >> num1 >> operation >> num2;

    switch (operation) {
        case '+':
            cout << "Ergebnis: " << num1 + num2 << endl;
        break;
        case '-':
            cout << "Ergebnis: " << num1 - num2 << endl;
        break;
        case '*':
            cout << "Ergebnis: " << num1 * num2 << endl;
        break;
        case '/':
            if (num2 != 0) {
                cout << "Ergebnis: " << num1 / num2 << endl;
            } else {
                cout << "Fehler: Division durch Null ist nicht erlaubt." << endl;
            }
        break;
        default:
            cout << "Fehler: Ungültiger Operator." << endl;
    }
}

int main() {
    char choice;
    do {
        calculator();
        cout << "Möchten Sie eine weitere Berechnung durchführen? (j/n): ";
        cin >> choice;
    } while (choice == 'j' || choice == 'J');

    cout << "Danke, dass Sie den Taschenrechner benutzt haben!\n";
    return 0;
}
