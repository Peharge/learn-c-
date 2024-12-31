#include <iostream>
using namespace std;

// Funktion für die Umrechnung von Längen
double lengthConverter(double value, string fromUnit, string toUnit) {
    // Umrechnungstabelle für Längen
    if (fromUnit == "Meter" && toUnit == "Kilometer") {
        return value / 1000;
    } else if (fromUnit == "Kilometer" && toUnit == "Meter") {
        return value * 1000;
    } else if (fromUnit == "Meter" && toUnit == "Zentimeter") {
        return value * 100;
    } else if (fromUnit == "Zentimeter" && toUnit == "Meter") {
        return value / 100;
    }
    return value; // Wenn keine Umrechnung definiert ist
}

// Funktion für die Umrechnung von Gewicht
double weightConverter(double value, string fromUnit, string toUnit) {
    // Umrechnungstabelle für Gewicht
    if (fromUnit == "Kilogramm" && toUnit == "Gramm") {
        return value * 1000;
    } else if (fromUnit == "Gramm" && toUnit == "Kilogramm") {
        return value / 1000;
    } else if (fromUnit == "Kilogramm" && toUnit == "Pfund") {
        return value * 2.20462;
    } else if (fromUnit == "Pfund" && toUnit == "Kilogramm") {
        return value / 2.20462;
    }
    return value;
}

// Funktion für die Umrechnung von Temperatur
double temperatureConverter(double value, string fromUnit, string toUnit) {
    // Umrechnung von Celsius zu Fahrenheit und umgekehrt
    if (fromUnit == "Celsius" && toUnit == "Fahrenheit") {
        return value * 9.0 / 5.0 + 32;
    } else if (fromUnit == "Fahrenheit" && toUnit == "Celsius") {
        return (value - 32) * 5.0 / 9.0;
    }
    return value; // Keine Umrechnung nötig
}

int main() {
    int choice;
    double value;
    string fromUnit, toUnit;

    cout << "Einheitenumrechner\n";
    cout << "1. Längenumrechner\n";
    cout << "2. Gewichtsumrechner\n";
    cout << "3. Temperaturumrechner\n";
    cout << "Wählen Sie eine Option (1-3): ";
    cin >> choice;

    cout << "Geben Sie den Wert ein, den Sie umrechnen möchten: ";
    cin >> value;

    switch (choice) {
        case 1:
            cout << "Geben Sie die Einheit ein, von der umgerechnet werden soll (z.B. Meter, Kilometer, Zentimeter): ";
            cin >> fromUnit;
            cout << "Geben Sie die Einheit ein, in die umgerechnet werden soll (z.B. Meter, Kilometer, Zentimeter): ";
            cin >> toUnit;
            cout << value << " " << fromUnit << " = " << lengthConverter(value, fromUnit, toUnit) << " " << toUnit << endl;
            break;

        case 2:
            cout << "Geben Sie die Einheit ein, von der umgerechnet werden soll (z.B. Kilogramm, Gramm, Pfund): ";
            cin >> fromUnit;
            cout << "Geben Sie die Einheit ein, in die umgerechnet werden soll (z.B. Kilogramm, Gramm, Pfund): ";
            cin >> toUnit;
            cout << value << " " << fromUnit << " = " << weightConverter(value, fromUnit, toUnit) << " " << toUnit << endl;
            break;

        case 3:
            cout << "Geben Sie die Einheit ein, von der umgerechnet werden soll (Celsius oder Fahrenheit): ";
            cin >> fromUnit;
            cout << "Geben Sie die Einheit ein, in die umgerechnet werden soll (Celsius oder Fahrenheit): ";
            cin >> toUnit;
            cout << value << " " << fromUnit << " = " << temperatureConverter(value, fromUnit, toUnit) << " " << toUnit << endl;
            break;

        default:
            cout << "Ungültige Auswahl!" << endl;
            break;
    }

    return 0;
}
