#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Подключение сигналов и слотов
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->actionExit, &QAction::triggered, this, &QApplication::quit);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::onActionOpenTriggered);
    connect(ui->actionDriver, &QAction::triggered, this, &MainWindow::onDriverTriggered);
    connect(ui->action, &QAction::triggered, this, &MainWindow::onCalendarTriggered);
}

// MainWindow::~MainWindow() {
//     delete ui;
// }

void MainWindow::onPushButtonClicked() const {
    // Логика при нажатии кнопки
    QString message = "Radio button НЕ выбран";

    if (ui->radioButton->isChecked()) {
        message = "Radio button выбран: " + ui->radioButton->text();
    }
    if (ui->radioButton_2->isChecked()) {
        message = "Radio button выбран: " + ui->radioButton_2->text();
    }
    ui->statusbar->showMessage(message);
}

void MainWindow::onActionOpenTriggered() {
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Открыть файл"),
        QDir::homePath(),
        tr("Все файлы (*.*);;Текстовые файлы (*.txt)")
    );

    if (!fileName.isEmpty()) {
        ui->statusbar->showMessage("Выбран файл: " + fileName);
    }
}

void MainWindow::onDriverTriggered() const {
    // ui->statusbar->showMessage("Привет!!!! :" + ui->horizontalSlider->value());
    // const QString ttt = itoa(ui->horizontalSlider->value());
    ui->statusbar->showMessage("Привет!!!! :"  + QString::number(ui->horizontalSlider->value()));
}

void MainWindow::onCalendarTriggered() const {
    ui->statusbar->showMessage(
    ui->calendarWidget->selectedDate().toString("dd.MM.yyyy"));

}
