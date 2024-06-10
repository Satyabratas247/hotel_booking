#include "roomavailabledialog.h"
#include "ui_roomavailabledialog.h"

RoomAvailableDialog::RoomAvailableDialog(QWidget *parent, int hotelno) :
    QDialog(parent),
    ui(new Ui::RoomAvailableDialog)
{
    ui->setupUi(this);
    this->hotelno = hotelno;
    setWindowTitle("Room Available");
}

RoomAvailableDialog::~RoomAvailableDialog()
{
    delete ui;
}

void RoomAvailableDialog::on_btnok_clicked()
{
    this->reject();
}

void RoomAvailableDialog::readData()
{
    qDebug() << "RoomAvailableDialog::readData";

    std::vector<int> rooms = hotel.getRoomList("Y",hotelno);

    std::vector<int>temprooms =  {101, 102, 103, 104, 105, 201, 202, 203, 204, 205, 301, 302, 303, 304, 305};

    for(std::vector<int>::iterator it = temprooms.begin(); it!=temprooms.end(); it++ )
    {
        QString lblname = "lbl" + QString::number(*it);
        QLabel * ptr = this->findChild<QLabel*>(lblname);

        if(ptr)
        {
            ptr->setStyleSheet("QLabel { background-color : lightgrey; color : black; }");
        }

    }

    for(std::vector<int>::iterator it = rooms.begin(); it!=rooms.end(); it++ )
    {
        QString lblname = "lbl" + QString::number(*it);
        QLabel * ptr = this->findChild<QLabel*>(lblname);

        if(ptr)
        {
            ptr->setStyleSheet("QLabel { background-color : grey; color : black; }");
        }

    }
}

