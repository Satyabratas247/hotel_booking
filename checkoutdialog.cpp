#include "checkoutdialog.h"
#include "ui_checkoutdialog.h"

CheckOutDialog::CheckOutDialog(QWidget *parent, int hotelno) :
    QDialog(parent),
    ui(new Ui::CheckOutDialog)
{
    ui->setupUi(this);
    this->hotelno = hotelno;
    setWindowTitle("Room Checkout");
}

CheckOutDialog::~CheckOutDialog()
{
    delete ui;
}

void CheckOutDialog::readData()
{
    std::vector<int> rooms = hotel.getRoomList("N",hotelno);
    this->ui->cmbRoomList->clear();
    for(std::vector<int>::iterator it = rooms.begin(); it!=rooms.end() ; it++)
    {
        this->ui->cmbRoomList->addItem(QString::number(*it));
    }
}

void CheckOutDialog::on_btnCheckout_clicked()
{
    int roomno = ui->cmbRoomList->currentText().toInt();

    if(roomno<1)
    {
        QMessageBox::information(this,tr("warning!"),tr("No room to checkout"));
        return;
    }

    int ret = hotel.CheckOut(roomno,hotelno);

    this->reject();

    if(ret==0)
    {
        QMessageBox::information(this,tr("success!"),tr("Room is checked out"));
    }
}


void CheckOutDialog::on_btnCancel_clicked()
{
    this->reject();
}

