#include <TApplication.h>
#include <TGClient.h>
#include <TGButton.h>
#include <TCanvas.h>
#include <TMessageBox.h>

// Callback-Funktion, die bei Klick auf den Button aufgerufen wird
void OnButtonClick() {
    new TMessageBox(kMBIconAsterisk, kMBOk, "Button wurde geklickt!");
}

int main(int argc, char **argv) {
    // ROOT Anwendung starten
    TApplication theApp("App", &argc, argv);

    // Erstelle das Hauptfenster
    TGMainFrame *mainWindow = new TGMainFrame(gClient->GetRoot(), 400, 200);

    // Button erstellen
    TGTextButton *button = new TGTextButton(mainWindow, "Klick mich!");
    button->Connect("Clicked()", "CppFunction", gClient->GetRoot(), "OnButtonClick()");

    // Layout und Anordnung der GUI
    mainWindow->AddFrame(button);
    button->CenterOnParent();
    mainWindow->SetWindowName("ROOT GUI Beispiel");
    mainWindow->MapSubwindows();
    mainWindow->Resize();
    mainWindow->MapWindow();

    // ROOT-Ereignisschleife starten
    theApp.Run();

    return 0;
}
