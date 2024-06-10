#ifndef BOOKINGDIALOG_H
#define BOOKINGDIALOG_H

#include <QDialog>
#include "bookroomdialog.h"
#include "checkoutdialog.h"
#include "roomavailabledialog.h"

namespace Ui {
class BookingDialog;
}

class BookingDialog : public QDialog
{
    Q_OBJECT

private:
    BookRoomDialog *ptrBookRoomDialog;
    CheckOutDialog *ptrCheckOutDialog;
    RoomAvailableDialog *ptrRoomAvailableDialog;
    int hotelno;
    int i;

public:
    explicit BookingDialog(QWidget *parent = nullptr,int hotelno = 1);
    ~BookingDialog();
    void ReadData();

private slots:
    void on_btnBookRoom_clicked();
    void on_btnCheckout_clicked();
    void on_btnRoomAvailable_clicked();
    void on_btnLeft_clicked();
    void on_btnRight_clicked();

private:
    Ui::BookingDialog *ui;
};

#endif // BOOKINGDIALOG_H
