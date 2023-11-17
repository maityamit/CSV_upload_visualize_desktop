#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    this->setStyleSheet("background-color: #1A1A1A;");

    // Create layout
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->setSpacing(5);

    // Create a TextView
    QTextBrowser *textBrowser = new QTextBrowser(this);
    textBrowser->setPlainText("This is My Assignment");
    textBrowser->setFixedSize(200, 50);
    textBrowser->setStyleSheet("font-size: 14pt; color: white;");
    layout->addWidget(textBrowser, 0, Qt::AlignHCenter | Qt::AlignVCenter);

    // Create a button
    QPushButton *button = new QPushButton("Upload CSV", this);
    button->setFixedSize(100, 50);
    button->setStyleSheet("background-color: #FFA116; color: white;");
    connect(button, &QPushButton::clicked, this, &MainWindow::showToast);
    layout->addWidget(button, 0, Qt::AlignHCenter | Qt::AlignVCenter);

    // Create a TextView
    QTextBrowser *textBrowser2 = new QTextBrowser(this);
    textBrowser2->setPlainText("- By Amit Maity");
    textBrowser2->setFixedSize(100, 50);
    textBrowser2->setStyleSheet("color: white;");
    layout->addWidget(textBrowser2, 0, Qt::AlignHCenter | Qt::AlignVCenter);

    // Set layout for central widget
    centralWidget->setLayout(layout);

    // Set window properties
    setGeometry(100, 100, 800, 600);
    setWindowTitle("CSV Upload and Visualize");
}

void MainWindow::showToast() {
    // Open a file dialog to select a .csv file
    QString filePath = QFileDialog::getOpenFileName(this, "Open .csv File", "", "CSV Files (*.csv)");

    if (!filePath.isEmpty()) {
        // Open the second window with the selected file path
        openSecondWindow(filePath);
    } else {
        // Display a message if no file was selected
        QMessageBox::warning(this, "No File Selected", "No .csv file selected.");
    }
}

void MainWindow::openSecondWindow(const QString& filePath) {
    // Create and show the second window
    SecondWindow *secondWindow = new SecondWindow(filePath, this);
    secondWindow->show();
}

SecondWindow::SecondWindow(const QString& filePath, QWidget *parent)
    : QMainWindow(parent) {
    // Set up the central widget layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Display the file path in a QTextBrowser
    QTextBrowser *textBrowser = new QTextBrowser(this);
    textBrowser->setPlainText("Selected .csv file:\n" + filePath);
    textBrowser->setStyleSheet("font-size: 14pt; color: white;");
    layout->addWidget(textBrowser, 0, Qt::AlignHCenter | Qt::AlignVCenter);

    // Create a back button
    QPushButton *backButton = new QPushButton("Back", this);
    connect(backButton, &QPushButton::clicked, this, &SecondWindow::close); // Close the second window on button click
    layout->addWidget(backButton, 0, Qt::AlignHCenter | Qt::AlignVCenter);

    // Set layout for the central widget
    centralWidget->setLayout(layout);

    // Set the central widget for the second window
    setCentralWidget(centralWidget);

    // Set window properties
    setGeometry(200, 200, 400, 300);
    setWindowTitle("Second Window");
}



MainWindow::~MainWindow() {
    // Note: ui is not defined in your provided code, make sure to handle it accordingly
    // delete ui;
}

SecondWindow::~SecondWindow() {
    // Destructor for cleanup if needed
}
