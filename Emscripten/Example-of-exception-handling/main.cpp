#include <iostream>
#include <stdexcept>  // Für Standardausnahmen wie std::out_of_range
using namespace std;

// Funktion zum Teilen von zwei Zahlen
double divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("Fehler: Division durch Null!");  // Ausnahme werfen
    }
    return a / b;
}

int main() {
    double num1, num2;

    cout << "Geben Sie zwei Zahlen zum Teilen ein: ";
    cin >> num1 >> num2;

    try {
        // Versuchen, die Division durchzuführen
        double result = divide(num1, num2);
        cout << "Das Ergebnis der Division ist: " << result << endl;
    }
    catch (const runtime_error& e) {
        // Ausnahme fangen und Fehlernachricht ausgeben
        cout << "Ausnahme gefangen: " << e.what() << endl;
    }

    return 0;
}
