#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Funktion zum Hinzufügen einer Aufgabe
void addTask(vector<string>& tasks) {
    string task;
    cout << "Gib die Aufgabe ein: ";
    cin.ignore(); // Puffer leeren, um Eingabefehler zu vermeiden
    getline(cin, task);
    tasks.push_back(task);
    cout << "Aufgabe hinzugefügt!\n";
}

// Funktion zum Löschen einer Aufgabe
void deleteTask(vector<string>& tasks) {
    int index;
    cout << "Gib die Nummer der Aufgabe ein, die du löschen möchtest: ";
    cin >> index;

    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Aufgabe gelöscht!\n";
    } else {
        cout << "Ungültige Aufgabe.\n";
    }
}

// Funktion zum Anzeigen der Aufgaben
void showTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Es gibt keine Aufgaben in der Liste.\n";
        return;
    }

    cout << "Deine Aufgaben:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

int main() {
    vector<string> tasks;
    int choice;

    while (true) {
        // Menü anzeigen
        cout << "\nTo-Do-Liste\n";
        cout << "1. Aufgabe hinzufügen\n";
        cout << "2. Aufgabe löschen\n";
        cout << "3. Aufgaben anzeigen\n";
        cout << "4. Beenden\n";
        cout << "Wähle eine Option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
            break;
            case 2:
                deleteTask(tasks);
            break;
            case 3:
                showTasks(tasks);
            break;
            case 4:
                cout << "Programm wird beendet.\n";
            return 0;
            default:
                cout << "Ungültige Auswahl! Versuche es nochmal.\n";
        }
    }

    return 0;
}
