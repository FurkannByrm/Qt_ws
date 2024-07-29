#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QMutex>
#include <QThread>
#include <QtCore>
#include <QDebug>

class myThread : public QObject
{
    Q_OBJECT
public:
    explicit myThread(QObject *parent = nullptr);
    myThread();
    void run();
    bool stop;
    QMutex _mutex;
    QThread* _thread;

signals:
   void valueChange(int);

};

#endif // MYTHREAD_H
