
#include <QRandomGenerator64>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SimpleCrypt.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_encrypt_clicked()
{
    const QString text = ui->text->toPlainText().trimmed();
    const quint64 key = getKey();

    if(key > 0 && !text.isEmpty())
    {
        SimpleCrypt crypto(key);
        ui->text->setPlainText(crypto.encryptToString(text));
    }
}

void MainWindow::on_decrypt_pressed()
{
    const QString text = ui->text->toPlainText().trimmed();
    const quint64 key = getKey();

    if(key > 0 && !text.isEmpty())
    {
        SimpleCrypt crypto(key);
        ui->text->setPlainText(crypto.decryptToString(text));
    }
}

void MainWindow::on_generateKey_clicked()
{
    QRandomGenerator64 generator;
    ui->key->setText(QString::number(generator.generate(), 16).toUpper());
}

void MainWindow::on_loadFromFile_clicked()
{
    const QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"));

    if(!fileName.isEmpty())
    {
        QFile file(fileName);

        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            ui->text->setPlainText(file.readAll());
        }
        else QMessageBox::warning(this,
                                  tr("Error"),
                                  tr("Unable to open file")
                                  );
    }
}

void MainWindow::on_saveToFile_clicked()
{
    const QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"));

    if(!fileName.isEmpty())
    {
        QFile file(fileName);

        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream outputStream(&file);
            outputStream << ui->text->toPlainText();
        }
        else QMessageBox::warning(this,
                                  tr("Error"),
                                  tr("Unable to save file")
                                  );
    }
}

quint64 MainWindow::getKey()
{
    const quint64 key = ui->key->text().toULongLong(nullptr, 16);

    if(key == 0) QMessageBox::warning(this,
                                      tr("Warning"),
                                      tr("Please, insert a valid key")
                                      );
    return key;
}
