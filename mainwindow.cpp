#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Hotel Booking");


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btnhotel_1_clicked()
{
    BookingDialog *booking = new BookingDialog(this,1);
    booking->ReadData();
    booking->show();
}


void MainWindow::on_btnhotel_2_clicked()
{
    BookingDialog *booking = new BookingDialog(this,2);
    booking->ReadData();
    booking->show();
}


void MainWindow::on_btnhotel_3_clicked()
{
    BookingDialog *booking = new BookingDialog(this,3);
    booking->ReadData();
    booking->show();
}


void MainWindow::on_btnhotel_4_clicked()
{
    BookingDialog *booking = new BookingDialog(this,4);
    booking->ReadData();
    booking->show();
}


void MainWindow::on_btnhotel_5_clicked()
{
    BookingDialog *booking = new BookingDialog(this,5);
    booking->ReadData();
    booking->show();
}


void MainWindow::on_btnhotel_6_clicked()
{
    BookingDialog *booking = new BookingDialog(this,6);
    booking->ReadData();
    booking->show();
}

