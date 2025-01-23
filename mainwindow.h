#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
} // Пространство имен для UI
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    // ~MainWindow();

private slots:
    void onPushButtonClicked() const; // Слот для нажатия кнопки
    void onActionOpenTriggered(); // Слот для открытия файла

private:
    Ui::MainWindow *ui; // Указатель на UI
};

#endif // MAINWINDOW_H
