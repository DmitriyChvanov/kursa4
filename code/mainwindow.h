#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void solveButtonClicked();

private:
    QPushButton *solveButton;
    QLineEdit *aLineEdit;
    QLineEdit *bLineEdit;
    QLineEdit *cLineEdit;
    QLabel *resultLabel;
};

#endif // MAINWINDOW_H
