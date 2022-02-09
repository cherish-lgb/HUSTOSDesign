#include "systemMonitor.h"
#include "ui_systemMonitor.h"
#include<cstdio>
#include<sys/sysinfo.h>
#include<time.h>
#include<errno.h>
using std::cout;
using std::endl;
systemMonitor::systemMonitor(QMainWindow* parent1):QMainWindow(parent1), ui(new Ui::systemMonitor){
    ui->setupUi(this);
    timer = new QTimer(this);
    showStartTime();
    connect(timer , SIGNAL(timeout()) , this , SLOT(updateUsage()));
    timer->start(1);
}

void systemMonitor::updateUsage(){
    updateSystemMessage();
    updateTime();
    updateCPUUsage();
    updateMemoryUsage();
    updateCPUInformation();
    updateProcess();

}
void systemMonitor::processOpenFileError(){
    QMessageBox::warning(this , tr("warning") , tr("The stat file can not open!"),QMessageBox::Yes);
    return ;
}
void systemMonitor::updateSystemMessage(){
    QFile qFile;
    qFile.setFileName("/proc/sys/kernel/hostname");
    if(!qFile.open(QIODevice::ReadOnly)){
        processOpenFileError();
        return ;
    }
    QString s = qFile.readLine();
    ui->setHostName->setText(s);
    qFile.close();
    qFile.setFileName("/proc/sys/kernel/ostype");
    if(!qFile.open(QIODevice::ReadOnly)){
        processOpenFileError();
        return ;
    }
    s = qFile.readLine();
    QString OSType = s.trimmed();
    qFile.close();
    qFile.setFileName("/proc/sys/kernel/osrelease");
    if(!qFile.open(QIODevice::ReadOnly)){
        processOpenFileError();
        return ;
    }
    s = qFile.readLine();
    OSType.append(" " + s.trimmed());
    ui->setVersion->setText(OSType);
    qFile.close();
    return ;
}
void systemMonitor::showStartTime(){
    struct sysinfo info;
    time_t curTime = 0 , bootTime = 0;
    struct tm* ptm = nullptr;
    if(sysinfo(&info)){
        cout << "error" <<endl;
        return ;
    }
    time(&curTime);
    if(curTime > info.uptime) bootTime = curTime - info.uptime;
    else bootTime = info.uptime - curTime;
    ptm = gmtime(&bootTime);
    QString s = QString::number(ptm->tm_year + 1900 , 10) + " years " +
            QString::number(ptm->tm_mon + 1 , 10) + " month " +
            QString::number(ptm->tm_mday , 10) + " hours " +
             QString::number(ptm->tm_min , 10) + " minutes " +
             QString::number(ptm->tm_sec , 10) + " seconds";
    ui->setStartRunTime->setText(s);
}

void systemMonitor::updateTime(){
    QFile qFile;
    qFile.setFileName("/proc/uptime");
    if(!qFile.open(QIODevice::ReadOnly)){
        processOpenFileError();
        return ;
    }
    QString s = qFile.readLine();
    int runTime = s.section(" " , 0 , 0).trimmed().toDouble();
    int hours = runTime / 3600, minutes = runTime % 3600 / 60, seconds  = runTime % 60;
    QString res = QString::number(hours , 10) + " hours " + QString::number(minutes , 10) + " minutes " + QString::number(seconds , 10) + " seconds";
    ui->setRunningTime->setText(res);
    qFile.close();
    return ;
}

double cal(QString& s){
    return s.mid(10 , s.size() - 13).trimmed().toDouble();
}

void systemMonitor::updateMemoryUsage(){
    QFile qFile;
    // memory information
    qFile.setFileName("/proc/meminfo");
    if(!qFile.open(QIODevice::ReadOnly)) exit(0);
    //The first line is the total memory information
    QString s = qFile.readLine();
    double total = cal(s) / 1024.0/1024;
    ui->setMemoryTotal->setText(QString::number(total , 'f' , 1) + " GB");
    s = qFile.readLine();
    double used = total - cal(s)/1024.0/1024.0;
    ui->setMemoryUsed->setText(QString::number(used , 'f' , 1) + " GB");
    ui->memoryUsage->setValue(used * 100 / total);
    qFile.close();
}

void systemMonitor::updateCPUInformation(){
    QFile qFile;
    qFile.setFileName("/proc/cpuinfo");
    if(!qFile.open(QIODevice::ReadOnly)){
        processOpenFileError();
        return ;
    }
    QString CPUName , CPUHZ , CPUCores;
    int pos = -1;
    while(true){
        QString s = qFile.readLine();
        if((pos = s.indexOf("model name")) != -1) CPUName = s.section(":" , 1 , 1);
        if((pos = s.indexOf("cpu MHz")) != -1) CPUHZ = s.section(":" , 1 , 1);
        if((pos = s.indexOf("cpu cores")) != -1){
            CPUCores = s.section(":" , 1 , 1);
            break;
        }
    }
    qFile.close();
    ui->setDominantFrequency->setText(CPUHZ);
    ui->setCPUType->setText(CPUName);
    ui->setNumberOfCores->setText(CPUCores);
    return ;
}

void systemMonitor::updateCPUUsage(){

}

void systemMonitor::updateProcess(){

}
void systemMonitor::updateProc(int pid){

}


