#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Verbinde den Button mit der Slot-Funktion
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot-Funktion, die beim Klicken auf den Button aufgerufen wird
void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this, "Info", "Button wurde geklickt!");
}
