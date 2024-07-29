#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "mythread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();
    myThread* _mythread;
private:
    Ui::Window *ui;
public slots:
    void onNumberChange(int);
private slots:
   void onPushButtonClicked();
   void onPushButton2Clicked();
};
#endif // WINDOW_H
