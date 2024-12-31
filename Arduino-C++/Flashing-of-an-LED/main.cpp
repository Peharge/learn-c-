// Definiere den Pin, an dem die LED angeschlossen ist
const int ledPin = 13;  // Pin 13 ist auf vielen Arduino-Boards mit einer integrierten LED verbunden

void setup() {
    // Setze den LED-Pin als Ausgang
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // Schalte die LED ein
    digitalWrite(ledPin, HIGH);
    // Warte 1 Sekunde
    delay(1000);

    // Schalte die LED aus
    digitalWrite(ledPin, LOW);
    // Warte 1 Sekunde
    delay(1000);
}
