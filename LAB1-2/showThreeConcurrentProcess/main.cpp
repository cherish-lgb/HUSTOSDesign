#include "mainwindow.h"
#include "process.h"
#include <QApplication>
#include<sys/types.h>
#include<unistd.h>
#include<iostream>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<cstring>
#include<QString>
#include<QTimer>

union semun{
    int val;
    struct semid_ds* buf;
    unsigned short* array;
    struct seminfo* __buf;
};

union semun arg;
const int N = 20;

char* bufPut;
char* bufGet;
int semid;
int main(int argc, char *argv[])
{
    using std::cout;
    using std::endl;
   int shmid = shmget((key_t)1000 , 1000 , IPC_CREAT | 0666);
   if(shmid == -1){
       cout << "shmget error" <<endl;
       return 1;
   }
   bufPut = (char*)shmat(shmid , 0 , 0);
   if(bufPut == NULL){
       cout << "shmat error" <<endl;
       return 1;
   }
   int shmid1 = shmget((key_t)3000 , 3000 , IPC_CREAT | 0666);
   if(shmid1 == -1){
       cout << "shmget error" <<endl;
       return 1;
   }
   bufGet = (char*)shmat(shmid1 , 0 , 0);
   if(bufGet == NULL){
       cout << "shmat error" <<endl;
       return 1;
   }
   semid = semget(10 , 4 , IPC_CREAT |0666);

   if(semid == -1){
       cout << "semget error!" <<'\n';
       return 1;
   }
   arg.val = 1;
   semctl(semid , 0 , SETVAL , arg);
   arg.val = 0;
   semctl(semid , 1 , SETVAL , arg);
   arg.val = 1;
   semctl(semid , 2 , SETVAL , arg);
   arg.val = 0;
   semctl(semid , 3 , SETVAL , arg);
   for(int i = 0 ; i < N ; ++i){
       bufGet[i] = '.';
       bufPut[i] = '.';
   }
   bufGet[N] = 0;
   bufPut[N] = 0;
   //QApplication a(argc , argv);
   if(fork()== 0){
       //cout << "child 1 start " <<endl;
       QApplication a(argc , argv);
       Process process(nullptr , 200 , 400 , N);
       process.setWindowTitle("Read from file");
       process.mySetText("current data:");
       process.setSemid(semid);
       process.change(QString(bufPut));
       process.show();
       QTimer* timer = new QTimer();
       Process::connect(timer , &QTimer::timeout , &process , &Process::updateProduct);
       timer->start(3000);
       return a.exec();
   }
   else if(fork() == 0){
       //cout << "child 2 start " <<endl;
        QApplication a(argc , argv);
        Process process(nullptr , 600 , 400 , N);
        process.setWindowTitle("Put data to bufPut");
        process.mySetText("Put Data:");
        process.setSemid(semid);
        process.change(QString(bufPut));
        process.show();
        QTimer* timer = new QTimer();
        Process::connect(timer , &QTimer::timeout , &process , &Process::updatePut);
        timer->start(3000);
        return a.exec();
   }
   else if(fork() == 0){
       //cout << "child 3 start " <<endl;
       QApplication a(argc , argv);
       Process process(nullptr , 1000 , 400 , N);
       process.setWindowTitle("Get data from bufGet");
       process.mySetText("Get Data:");
       process.setSemid(semid);
       process.change(QString(bufGet));
       process.show();
       QTimer* timer = new QTimer();
       Process::connect(timer , &QTimer::timeout , &process , &Process::updateGet);
       timer->start(3000);
       return a.exec();
   }
   //semctl(semid , 4 , IPC_RMID , arg);
   return 0;
}
