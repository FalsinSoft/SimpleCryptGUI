#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_generateKey_clicked();
    void on_loadFromFile_clicked();
    void on_saveToFile_clicked();
    void on_encrypt_clicked();
    void on_decrypt_pressed();

private:
    Ui::MainWindow *ui;

    quint64 getKey();
};
#endif // MAINWINDOW_H
