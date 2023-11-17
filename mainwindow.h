#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QVBoxLayout>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class SecondWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void showToast();
    void openSecondWindow(const QString& filePath);

private:
    Ui::MainWindow *ui;
    QVBoxLayout *layout;
    QPushButton *button;
};


class SecondWindow : public QMainWindow {
    Q_OBJECT

public:
    SecondWindow(const QString& filePath, QWidget *parent = nullptr);
    ~SecondWindow();

private:

};

#endif // MAINWINDOW_H
