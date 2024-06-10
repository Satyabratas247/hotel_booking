#ifndef BOOKROOMDIALOG_H
#define BOOKROOMDIALOG_H

#include <QDialog>
#include <QDebug>
#include <vector>
#include <QMessageBox>
#include "hotel.h"

namespace Ui {
class BookRoomDialog;
}

class BookRoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookRoomDialog(QWidget *parent = nullptr, int hotelno = 1);
    ~BookRoomDialog();
    void readData();

private slots:
    void on_btnok_clicked();

    void on_btncancel_clicked();

private:
    Ui::BookRoomDialog *ui;
    Hotel *hotel;
    int hotelno;
};

#endif // BOOKROOMDIALOG_H
