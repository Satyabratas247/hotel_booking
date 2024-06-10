#include "bookingdialog.h"
#include "ui_bookingdialog.h"

BookingDialog::BookingDialog(QWidget *parent,int hotelno) :
    QDialog(parent),
    ui(new Ui::BookingDialog)
{
    ui->setupUi(this);
    this->hotelno = hotelno;
    this->i = 1;
    QPixmap pix(":/images/hotel_"+QString::number(this->hotelno)+"_1.jpg");
    ui->lblHotel->setPixmap(pix.scaled(800,800));
    ui->btnLeft->setDisabled(true);
    setWindowTitle("Booking");
}


BookingDialog::~BookingDialog()
{
    delete ui;
    delete ptrBookRoomDialog;
    delete ptrCheckOutDialog;
    delete ptrRoomAvailableDialog;
}

void BookingDialog::ReadData()
{
    switch(this->hotelno)
    {
    case 1:
        ui->lbl_description->setText("900 KANDI FOREST RESORT\n\nLocation : 900 kandi, wayanad \n\ncheck-in : 03:30PM \ncheck-out : 04:30PM \n\nPer head: 1400/- (3 share tent) \nper head: 1400/- (3 share dom) \nper couple: ₹5000/-\n\nINCLUDE\n\n• off road jeep drive\n• stream hiking\n• tea & snacks\n• stream bath\n• campfire with music\n• breakfast\n• trekking");
        break;
    case 2:
        ui->lbl_description->setText("VYTHIRI HAV WAYANAD\n\nLocation : vythiri, wayanad\n\ncheck in : 02:00PM\ncheck out: 11:00AM\n\nPer couples : ₹2999/- (mon-fri)\nper couples : ₹3499/- (sat-sun)\nper head: ₹999/- (mon-fri)\nper head: 1199/- (sat-sun)\n\nINCLUDE\n\n• Resort stay\n• swimming pool\n• breakfast\n• games");
        break;
    case 3:
        ui->lbl_description->setText("AVALI BANASURA\n\n\nLocation: banasura, wayanad\n\ncheck in : 02:00PM\ncheck out: 12:00PM\n\nPer head: ₹1000/- (minimum 4pax)\nper couple: ₹3000/- (mon-fri)\nper couple: ₹3500/- (sat-sun)\n\nINCLUDE\n\n• resort stay\n• swimming pool\n• breakfast\n• grilling facilities\n• game");
        break;
    case 4:
        ui->lbl_description->setText("BATHERI RESORT\n\n\nLocation : bathery, wayanad\n\ncheck in : 01:00PM\ncheck out: 11:00AM\n\nPer couples : ₹3000/-\nper head: 999/-\n\nINCLUDE\n\n• Resort stay\n• swimming pool\n• breakfast\n• games");
        break;
    case 5:
        ui->lbl_description->setText("TEA PLANTATION MEPPADI\nLocation : meppadi, vaduvanchal, wayanad\n\ncheck-in : 01:00PM\ncheck-out : 01:00PM\n\nPer head: 1450/- (minimum 4pax)\nper couples: ₹3700/-\n\nINCLUDE\n\n• Swimming pool (time 07 to 10)\n• badminton\n• view point\n• river side walk\n• plantation visit (300Acer land)\n• restaurant facility");
        break;
    case 6:
        ui->lbl_description->setText("VYTHRY RIVER SIDE STAY\n\n\nLocation : vythiri, wayanad\n\ncheck in : 02:00PM\ncheck out: 11:00AM\n\nPER HEAD : ₹900/- (MINIMUM 4)\nPER COUPLE: ₹1999/- (IN BHK)\nPER COUPLE: ₹2499/-\n\nINCLUDE\n\nHome stay swimming pool\n• shuttle court\n\nHey... Amount will change depending season");
        break;

    }

}



void BookingDialog::on_btnBookRoom_clicked()
{
    ptrBookRoomDialog = new BookRoomDialog(this,hotelno);
    ptrBookRoomDialog->readData();
    ptrBookRoomDialog->show();

    if(ptrBookRoomDialog->isVisible())
        qDebug() << "Dialog box is visible";
    else
        qDebug() << "Dialog box is not visible";
}


void BookingDialog::on_btnCheckout_clicked()
{
    ptrCheckOutDialog = new CheckOutDialog(this,hotelno);
    ptrCheckOutDialog->readData();
    ptrCheckOutDialog->show();

    if(ptrCheckOutDialog->isVisible())
        qDebug() << "Dialog box is visible";
    else
        qDebug() << "Dialog box is not visible";
}


void BookingDialog::on_btnRoomAvailable_clicked()
{
    ptrRoomAvailableDialog = new RoomAvailableDialog(this,hotelno);
    ptrRoomAvailableDialog->readData();
    ptrRoomAvailableDialog->show();

    if(ptrRoomAvailableDialog->isVisible())
        qDebug() << "Dialog box is visible";
    else
        qDebug() << "Dialog box is not visible";
}


void BookingDialog::on_btnLeft_clicked()
{
    --i;
    if(i==6)
        ui->btnRight->setDisabled(true);
    else if(i==1)
        ui->btnLeft->setDisabled(true);
    else
        ui->btnRight->setDisabled(false);
    QPixmap pix(":/images/hotel_"+QString::number(hotelno)+"_"+QString::number(i)+".jpg");
    ui->lblHotel->setPixmap(pix.scaled(800,800));
}


void BookingDialog::on_btnRight_clicked()
{
    ++i;
    if(i==1)
        ui->btnLeft->setDisabled(true);
    else if (i==6)
        ui->btnRight->setDisabled(true);
    else
        ui->btnLeft->setDisabled(false);
    QPixmap pix(":/images/hotel_"+QString::number(hotelno)+"_"+QString::number(i)+".jpg");
    ui->lblHotel->setPixmap(pix.scaled(800,800));
}

