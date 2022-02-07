#include "mainwindow.h"
#include "process.h"
#include <QApplication>
#include<sys/types.h>
#include<iostream>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<cstring>
#include<QString>

union semun{
    int val;
    struct semid_ds* buf;
    unsigned short* array;
    struct seminfo* _buf;
};
void P(int semid, int index){
    struct sembuf sem;
    sem.sem_num = index;
    sem.sem_op = -1;
    sem.sem_flg = 0;
    semop(semid , &sem , 1);
    return ;
}
void V(int semid, int index){
    struct sembuf sem;
    sem.sem_num = index;
    sem.sem_op = 1;
    sem.sem_flg = 0;
    semop(semid , &sem , 1);
    return ;
}
union semun arg;
const int N = 20;
char bufPut[N];
char bufGet[N];
int main(int argc, char *argv[])
{
    using std::cout;
    using std::endl;
   int semid = semget(10 , 4 , IPC_CREAT |0666);
   if(semid == -1){
       cout << "semget error!" <<'\n';
       return 1;
   }
   for(int i = 0 ; i < 4 ; ++i){
       if(i % 2 == 0) arg.val = 1;
       else arg.val = 0;
       if(semctl(semid , i , SETVAL , arg) < 0){
           cout << "semctl error!" <<endl;
           return 1;
       }
   }
   int pid = 0;
   if((pid = fork()) == 0){
       QApplication a(argc , argv);
       Process process(nullptr , 600 , 400);
       process.setWindowTitle("Read from file");
       process.mySetText("current data:");
       process.show();

       int idx = 0 , p = 2;
       while(true){
            P(semid , 0);
            QString s;
            for(int i = 0 ; i < N ; ++i){
                idx = (idx + p) % 26;
                char ch = 'a' + idx;
                s.append(ch);
                p = (p * 2) % 26;
                if(p == 0) p = 1;
                bufPut[i] = ch;
            }
            process.change(s);
            V(semid , 1);
       }
       a.exec();
       exit(0);
   }

    return 0;
}
