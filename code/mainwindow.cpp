#include "mainwindow.h"
#include <cmath>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Создание виджетов
    aLineEdit = new QLineEdit(this);
    aLineEdit->setPlaceholderText("Введите a");

    bLineEdit = new QLineEdit(this);
    bLineEdit->setPlaceholderText("Введите b");

    cLineEdit = new QLineEdit(this);
    cLineEdit->setPlaceholderText("Введите c");

    solveButton = new QPushButton("Решить", this);
    connect(solveButton, &QPushButton::clicked, this, &MainWindow::solveButtonClicked);

    resultLabel = new QLabel(this);

    // Размещение виджетов на главном окне
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(aLineEdit);
    layout->addWidget(bLineEdit);
    layout->addWidget(cLineEdit);
    layout->addWidget(solveButton);
    layout->addWidget(resultLabel);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void MainWindow::solveButtonClicked()
{
    // Получение коэффициентов a, b, c из полей ввода
    double a = aLineEdit->text().toDouble();
    double b = bLineEdit->text().toDouble();
    double c = cLineEdit->text().toDouble();

    // Расчет дискриминанта
    double discriminant = b * b - 4 * a * c;

    // Проверка наличия корней
    if (discriminant >= 0)
    {
        // Расчет корней
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);

        // Отображение результата
        resultLabel->setText(QString("Корни уравнения: x1 = %1, x2 = %2").arg(x1).arg(x2));
    }
    else
    {
        // Отображение сообщения об отсутствии корней
        resultLabel->setText("Уравнение не имеет действительных корней");
    }
}

