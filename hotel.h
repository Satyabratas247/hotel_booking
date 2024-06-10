#ifndef HOTEL_H
#define HOTEL_H

#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <vector>
#include <algorithm>

class Hotel
{
private:
    //Hotel(){} // null constructor
    //Hotel(Hotel const &){}

public:
    Hotel(){} // null constructor
    Hotel(Hotel const &){}
    int BookRoom(int roomno, QString name, QString contactno, QString address, QString idproof, int hotelno);
    int CheckOut(int roomno, int hotelno);
    std::vector<int> getRoomList(QString Availabilility, int hotelno = 1);

};
#endif // HOTEL_H
