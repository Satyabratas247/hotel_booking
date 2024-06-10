#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bookingdialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_btnhotel_1_clicked();

    void on_btnhotel_2_clicked();

    void on_btnhotel_3_clicked();

    void on_btnhotel_4_clicked();

    void on_btnhotel_5_clicked();

    void on_btnhotel_6_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
