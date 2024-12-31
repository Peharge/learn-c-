#include "stdafx.h"
#include <windows.h>
#include <string>
using namespace System;
using namespace System::Windows::Forms;

public ref class MainForm : public Form
{
public:
    MainForm()
    {
        // Initialisiere das Formular
        this->Text = "Managed C++ Beispiel";
        this->Size = System::Drawing::Size(300, 200);

        // Erstelle einen Button
        Button^ button = gcnew Button();
        button->Text = "Klick mich!";
        button->Location = System::Drawing::Point(100, 70);

        // Füge einen Click-Event-Handler hinzu
        button->Click += gcnew EventHandler(this, &MainForm::OnButtonClick);

        // Füge den Button zum Formular hinzu
        this->Controls->Add(button);
    }

private:
    // Event-Handler für den Button-Klick
    void OnButtonClick(Object^ sender, EventArgs^ e)
    {
        MessageBox::Show("Button wurde geklickt!", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
};

[STAThread]
int main(array<String^>^ args)
{
    // Starte die Anwendung mit dem Form
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MainForm());
    return 0;
}
