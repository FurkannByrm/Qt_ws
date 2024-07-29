#include "window.h"
#include "./ui_window.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    _mythread = new myThread(this);
    ui->setupUi(this);
    connect(_mythread, SIGNAL(valueChange(int)), this, SLOT(onNumberChange(int)));
}

Window::~Window()
{
    delete ui;
}
void Window::onNumberChange(int Number)
{

}
