#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(released()),this,SLOT(onPushButtonClick()));
    connect(ui->pushButton,SIGNAL(released()),this,SLOT(hide()));

    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(onPushButton_2Click()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(hide()));
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete gameWindowPvP;
    //delete gameWindowPvE;
}

void MainWindow::onPushButtonClick()
{
    int dim = ui->spinBox->value();
    gameWindowPvP = new GameWindowPvP(this, dim);
    gameWindowPvP->show();
}

void MainWindow::onPushButton_2Click()
{
    int dim = ui->spinBox->value();
    int depth = ui->spinBox_2->value();
    bool aiStart = ui->checkBox->isChecked();
    gameWindowPvE = new GameWindowPvE(this, dim, aiStart, depth);
    gameWindowPvE->show();
}
