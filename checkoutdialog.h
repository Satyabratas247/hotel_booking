#ifndef CHECKOUTDIALOG_H
#define CHECKOUTDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include "hotel.h"

namespace Ui {
class CheckOutDialog;
}

class CheckOutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckOutDialog(QWidget *parent = nullptr, int hotelno = 1);
    ~CheckOutDialog();
    void readData();
    Hotel hotel;

private slots:
    void on_btnCheckout_clicked();

    void on_btnCancel_clicked();

private:
    Ui::CheckOutDialog *ui;
    int hotelno;
};

#endif // CHECKOUTDIALOG_H
