#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->mTextEdit); // Text Edit control takes all free space
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_actionNew_triggered()
{
   currentFile.clear();
   ui->mTextEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open File");
    QFile file(filename);
    currentFile = filename;
    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
    }
    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->mTextEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
   QString filename = QFileDialog::getSaveFileName(this, "Save File As");
   QFile file(filename);
   if (filename.isEmpty()) return;

   // Ensure that file opens in write mode for saving
   if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
   {
       QMessageBox::warning(this, "Error", "Cannot save file: " + file.errorString());
   }
   QTextStream out(&file);

   // Write all text to the file
   out << ui->mTextEdit->toPlainText() << "\n";
   file.close();
}

void MainWindow::on_actionSave_triggered()
{
   QString filename = currentFile;
   QFile file(filename);
   if (filename.isEmpty()) return;

   if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
   {
       QMessageBox::warning(this, "Error", "Cannot save file: " + file.errorString());
   }
   QTextStream out(&file);

   out << ui->mTextEdit->toPlainText() << "\n";
   file.close();
}

void MainWindow::on_actionQuit_triggered() { QApplication::quit(); }

void MainWindow::on_actionUndo_triggered() { ui->mTextEdit->undo(); }

void MainWindow::on_actionRedo_triggered() { ui->mTextEdit->redo(); }

void MainWindow::on_actionCut_triggered() { ui->mTextEdit->cut(); }

void MainWindow::on_actionCopy_triggered() { ui->mTextEdit->copy(); }

void MainWindow::on_actionPaste_triggered() { ui->mTextEdit->paste(); }
