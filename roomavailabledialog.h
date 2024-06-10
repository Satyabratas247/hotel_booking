#ifndef ROOMAVAILABLEDIALOG_H
#define ROOMAVAILABLEDIALOG_H

#include <QDialog>
#include "hotel.h"
#include <QDebug>

namespace Ui {
class RoomAvailableDialog;
}

class RoomAvailableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RoomAvailableDialog(QWidget *parent = nullptr, int hotelno=1);
    ~RoomAvailableDialog();
    Hotel hotel;
    void readData();

private slots:
    void on_btnok_clicked();

private:
    Ui::RoomAvailableDialog *ui;
    int hotelno;
};

#endif // ROOMAVAILABLEDIALOG_H
