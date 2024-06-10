#include "hotel.h"

int Hotel::BookRoom(int roomno, QString name, QString contactno, QString address, QString idproof, int hotelno)
{
    qDebug() << "BookRoom : " << roomno;

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    db.setDatabaseName("Hotel");
    db.setUserName("postgres");
    db.setPassword("Prithan@17");

    if(db.open())
        qDebug() << "Connected to database";
    else
        qDebug() << db.lastError().text();

    QSqlQuery query(db);
    query.prepare("update \"Room\" set \"Available\" = 'N' where \"RoomNo\" = '" + QString::number((roomno)) + "' AND \"HotelNo\" ='" +QString::number(hotelno)+"'");

    if(query.exec())
        qDebug() << "Updated successfully !" << query.lastQuery();
    else
        qDebug() << query.lastError().text() << query.lastQuery();

    query.clear();
    query.prepare("insert into \"Customer\" (\"name\", \"mobileno\", \"address\", \"idproof\") values ('" + name + "','" + contactno + "','" + address + "','" + idproof +"');");

    QString customer_id;
    qDebug() << "Customer_id :" << customer_id;
    if(query.exec())
    {
        qDebug() << "updated successfully" << query.lastQuery();
        qDebug() << "Last inserted id is :" << query.lastInsertId().toString();
        customer_id = query.lastInsertId().toString();
    }
    else
        qDebug() << query.lastError().text() << query.lastQuery();

    query.clear();
    query.prepare("insert into \"Transaction\" (\"Room\", \"CustomerId\") values ('" + QString::number(roomno) + "','" + customer_id + "')");
    if(query.exec())
    {
        qDebug() <<"Updated successfully "<< query.lastQuery();
        qDebug() <<"Last Inserted Id is  : "<<query.lastInsertId().toString();
    }
    else
            qDebug() << query.lastError().text() << query.lastQuery();

    db.close();
    return 0;
}

int Hotel::CheckOut(int roomno, int hotelno)
{
    qDebug() << "Checkout : " << roomno;

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    db.setDatabaseName("Hotel");
    db.setUserName("postgres");
    db.setPassword("Prithan@17");

    if(db.open())
        qDebug() << "Connected to database";
    else
        qDebug() << db.lastError().text();

    QSqlQuery query(db);
    query.prepare("update \"Room\" set \"Available\" = 'Y' where \"RoomNo\" = '" + QString::number((roomno)) + "' AND \"HotelNo\" ='" +QString::number(hotelno)+"'");

    if(query.exec())
        qDebug() << "Updated successfully !" << query.lastQuery();
    else
        qDebug() << query.lastError().text() << query.lastQuery();


    db.close();
    return 0;
}

std::vector<int> Hotel::getRoomList(QString Availabilility = "Y", int hotelno)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    db.setDatabaseName("Hotel");
    db.setUserName("postgres");
    db.setPassword("Prithan@17");

    if(db.open())
        qDebug() << "Connected to database";
    else
        qDebug() << db.lastError().text();

    QSqlQuery query(db);
    query.prepare("select \"RoomNo\" from \"Room\" Where \"Available\" ='" + Availabilility +"' AND \"HotelNo\" ='" +QString::number(hotelno)+"'");

    if(query.exec())
        qDebug() << "Fetch was successful";
    else
        qDebug() << query.lastError().text();

    std :: vector<int> rooms;
    while(query.next())
    {
        QString roomno = query.value(0).toString();
        rooms.push_back(roomno.toInt());
        qDebug() << "Room no is:" << roomno;
    }
    std::sort(rooms.begin(),rooms.end());
    db.close();
    return rooms;
}
