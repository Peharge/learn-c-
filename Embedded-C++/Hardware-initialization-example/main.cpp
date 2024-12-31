#include "stm32f4xx.h"  // Header-Datei für STM32F4-Serie (je nach verwendetem Mikrocontroller ändern)

class GPIO {
public:
    // Konstruktor: Initialisiert den GPIO-Pin für die LED
    GPIO() {
        // Aktivieren des Clock für GPIOC
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

        // Konfigurieren des Pin 13 (PC13) als Ausgang
        GPIOC->MODER &= ~GPIO_MODER_MODE13;   // Maskieren der vorherigen Konfiguration
        GPIOC->MODER |= GPIO_MODER_MODE13_0;  // Setzen von Pin 13 als Ausgang (01)

        // Setzen des Output-Type als Push-Pull (Standard)
        GPIOC->OTYPER &= ~GPIO_OTYPER_OT_13;  // Standardwert: Push-Pull

        // Keine Pull-up / Pull-down Widerstände
        GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR13;
    }

    // Funktion zum Ein- und Ausschalten der LED
    void toggleLED() {
        GPIOC->ODR ^= GPIO_ODR_OD13;  // Wechseln des Status von PC13 (LED an/aus)
    }
};

int main() {
    GPIO gpio;  // Instanziierung des GPIO-Objekts, das den Pin steuert

    while (true) {
        gpio.toggleLED();  // LED umschalten
        for (volatile int i = 0; i < 1000000; i++) {  // Einfache Verzögerung
            // Diese Schleife erzeugt eine Verzögerung
            // Hier könnte ein Timer verwendet werden, aber eine einfache Schleife reicht fürs erste
        }
    }

    return 0;
}
