#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ms = 0;
    s = 0;
    m = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerSlot()));

    ui->pushButton->setText("СТАРТ");
    ui->pushButton_2->setText("СБРОС");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TimerSlot()
{
    ms++;
    if(ms>=1000)
    {
        ms = 0;
        s++;
    }
    if (s>=60)
    {
        s=0;
        m++;
    }
    ui->label->setText(QString::number(m) + " : ");
    ui->label_2->setText(QString::number(s));
    ui->label_3->setText(" : " + QString::number(ms));
}


void MainWindow::on_pushButton_clicked()
{
    flag = !flag;
    if(flag)
    {
         ui->pushButton->setText("СТАРТ");
         timer->stop();
    }
    else
    {
        ui->pushButton->setText("СТОП");
        timer ->start(1);
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    ms = 0;
    s = 0;
    m = 0;

    ui->label->setText(QString::number(m) + " : ");
    ui->label_2->setText(QString::number(s));
    ui->label_3->setText(" : " + QString::number(ms));
}

