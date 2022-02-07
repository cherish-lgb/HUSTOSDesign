#ifndef PROCESS_H
#define PROCESS_H
#include<sys/types.h>
#include<iostream>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<cstring>
#include<QString>
#include<QWidget>
#include "ui_Process.h"
namespace Ui {
    class Process;
}

class Process: public QWidget{
    Q_OBJECT
private:
    Ui::Process *ui;
public:
    explicit Process(QWidget *parent = nullptr , int x = 100 , int y = 100);
    void mySetText(QString s);
    void change(QString s);
    ~Process();
public slots:
    void Update();
};

#endif // PROCESS_H


