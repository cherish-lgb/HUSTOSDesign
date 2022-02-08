#ifndef PROCESS_H
#define PROCESS_H
#include<sys/types.h>
#include<iostream>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<cstring>
#include<QString>
#include<QWidget>
#include<sys/shm.h>
#include "ui_Process.h"
extern const int N;
namespace Ui {
    class Process;
}

class Process: public QWidget{
    Q_OBJECT
private:
    Ui::Process *ui;
    int idx = 0 , p = 2, N, semid;
    char* bufPut;
    char* bufGet;
    void P(int semid , int index);
    void V(int semid , int index);
public:
    explicit Process(QWidget *parent = nullptr , int x = 100 , int y = 100 , int n = 20);
    void mySetText(QString s);
    void change(QString s);
    void setSemid(int semid);
    ~Process();
public slots:
    void updateProduct();
    void updatePut();
    void updateGet();
};

#endif // PROCESS_H


