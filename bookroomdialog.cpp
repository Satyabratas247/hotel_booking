#include "bookroomdialog.h"
#include "ui_bookroomdialog.h"

BookRoomDialog::BookRoomDialog(QWidget *parent, int hotelno) :
    QDialog(parent),
    ui(new Ui::BookRoomDialog)
{
    ui->setupUi(this);
    this->hotelno = hotelno;
    setWindowTitle("Book Room");
}

BookRoomDialog::~BookRoomDialog()
{
    delete ui;
}

void BookRoomDialog::readData()
{
    qDebug() << "BookRoomDialog::readData";
    hotel = new Hotel();
    std::vector<int> rooms = hotel->getRoomList("Y",hotelno);

    this->ui->cmbroomno->clear();

    for(std::vector<int>::iterator it = rooms.begin();it!=rooms.end();it++)
    {
        this->ui->cmbroomno->addItem(QString::number(*it));
    }
}

void BookRoomDialog::on_btnok_clicked()
{
    int roomno = ui->cmbroomno->currentText().toInt();
    QString name = ui->txtname->text();
    QString mobileno = ui->txtmobileno->text();
    QString address = ui->txtaddress->text();
    QString idproof = ui->txtidproof->text();

    if(roomno<1)
    {
        QMessageBox::information(this,tr("warning!"),tr("No room available"));
        return;
    }

    int ret = hotel->BookRoom(roomno,name,mobileno,address,idproof,hotelno);

    this->reject();

    if(ret==0)
    {
        QMessageBox::information(this,tr("Success!"),tr("Room is booked"));

    }
}


void BookRoomDialog::on_btncancel_clicked()
{
    this->reject();
}

