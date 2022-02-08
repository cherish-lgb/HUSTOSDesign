#include "process.h"
#include "ui_Process.h"
#include <unistd.h>
#include <QTimer>
#include<iostream>
#include<QString>
Process::Process(QWidget *parent , int x , int y , int n):QWidget(parent) ,ui(new Ui::Process){
    ui->setupUi(this);
    this->setFixedSize(this->width() , this->height());
    this->move(x , y);
    int pid = getpid();
    ui->label_2->setText(QString::number(pid , 10));
    N = n;
    int shmid = shmget((key_t)1000 , 1000 , IPC_CREAT | 0666);
    if(shmid == -1){
        std::cout << "shmget error" << std:: endl;
        exit(0);
    }
    bufPut = (char*)shmat(shmid , 0 , 0);
    if(bufPut == NULL){
        std::cout << "shmat error" << std::endl;
        exit(0);
    }
    int shmid1 = shmget((key_t)3000 , 3000 , IPC_CREAT | 0666);
    if(shmid1 == -1){
        std::cout << "shmget error" <<std::endl;
        exit(0);
    }
    bufGet = (char*)shmat(shmid1 , 0 , 0);
    if(bufGet == NULL){
        std::cout << "shmat error" << std::endl;
        exit(0);
    }
}
void Process::change(QString s){
    ui->label_4->setText(s);
    return ;
}

void Process::mySetText(QString s){
    ui->label_3->setText(s);
    return ;
}
void Process::setSemid(int semid){
    this->semid = semid;
    return ;
}

void Process::updateProduct(){
   std::cout << semid << std::endl;
   QString str;
   for(int i = 0 ; i < N ; ++i){
    idx = (idx + p) % 26;
    char ch = 'a' + idx;
    str.append(ch);
    p = (p * 2) % 26;
    if(p == 0) p = 1;
   }
   change(str);
   std::cout << str.toStdString()<< std::endl;
   std::cout << bufPut << std::endl;
   P(semid , 0);
   for(int i = 0 ; i < N ; ++i) bufPut[i] = str.at(i).unicode();
   change(str);
   V(semid , 1);
   return ;
}
void Process::updatePut(){
    std::cout << semid << std::endl;
    P(semid , 1);
    P(semid , 2);
    QString str;
    for(int i = 0 ; i < N ; ++i){
        str.append(bufPut[i]);
        bufGet[i] = bufPut[i];
    }
    std::cout << bufGet << std::endl;
    change(str);
    V(semid , 0);
    V(semid , 3);
    sleep(0);
    return ;
}

void Process::updateGet(){
    std::cout << semid << std::endl;
    P(semid , 3);
    QString str;
    for(int i = 0 ; i < N ; ++i){
        str.append(bufGet[i]);
    }
    change(str);
    V(semid , 2);
    return ;
}
void Process::P(int semid, int index){
    struct sembuf sem;
    sem.sem_num = index;
    sem.sem_op = -1;
    sem.sem_flg = 0;
    semop(semid , &sem , 1);
    return ;
}
void Process::V(int semid, int index){
    struct sembuf sem;
    sem.sem_num = index;
    sem.sem_op = 1;
    sem.sem_flg = 0;
    semop(semid , &sem , 1);
    return ;
}

Process::~Process(){
    delete ui;
}

