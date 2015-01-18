#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QFileDialog>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _basePixmap(0)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;

    if (_basePixmap)
        delete _basePixmap;
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionOpen_triggered()
{
    QFileDialog fd(this, tr("Ouvrir une image"));
    fd.setFileMode(QFileDialog::ExistingFile);
    fd.setNameFilter(tr("Images (*.png *.jpg *.gif *.bmp)"));

    if (fd.exec())
    {
        _basePixmap = new QPixmap(fd.selectedFiles().first());
        ui->basePicture->setPixmap(*_basePixmap);
    }
}
