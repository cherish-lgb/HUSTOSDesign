#include "systemMonitor.h"
#include "ui_systemMonitor.h"
#include<cstdio>
#include<sys/sysinfo.h>
#include<time.h>
#include<errno.h>
#include<string>
#include<vector>
using std::stringstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
systemMonitor::systemMonitor(QMainWindow* parent1):QMainWindow(parent1), ui(new Ui::systemMonitor){
    ui->setupUi(this);
    initCurve();
    timer = new QTimer(this);
    showStartTime();
    QString information = "PID\tPPID\tName\t\t\t\tStat\tPriority\tMemoryUsage";
    new QListWidgetItem(information , ui->listWidgetProcess);
    connect(timer , SIGNAL(timeout()) , this , SLOT(updateUsage()));
    connect(ui->shutDownProcess , SIGNAL(clicked()) , this , SLOT(clickShutDownProcess()));
    connect(ui->shutDown , SIGNAL(clicked()) , this , SLOT(clickShutDown()));
    connect(ui->findProcess , SIGNAL(clicked()) , this , SLOT(clickFindProcess()));
    timer->start(10);
}
void systemMonitor::initCurve(){
    CPUQchart = new QChart();
    CPUChartView = new QChartView(this);
    CPUAxisX = new QValueAxis();
    CPUAxisY = new QValueAxis();
    CPUQchart->addAxis(CPUAxisX , Qt::AlignBottom);
    CPUQchart->addAxis(CPUAxisY , Qt::AlignLeft);
    CPUAxisX->setTickCount(5);
    CPUAxisX->setRange(0 , MAXN);
    CPUAxisY->setTickCount(2);
    CPUAxisY->setRange(0 , 100);
    CPUSeries = new QSplineSeries(this);
    CPUQchart->addSeries(CPUSeries);
    CPUQchart->setTitle("CPU Usage Curve");
    CPUSeries->attachAxis(CPUAxisX);
    CPUSeries->attachAxis(CPUAxisY);
    CPUChartView->setChart(CPUQchart);
    ui->setCPUUsagesCurve->addWidget(CPUChartView);
    CNTCPU = 0;
    MemoryQchart = new QChart();
    MemoryChartView = new QChartView(this);
    MemoryAxisX = new QValueAxis();
    MemoryAxisY = new QValueAxis();
    MemoryQchart->addAxis(MemoryAxisX , Qt::AlignBottom);
    MemoryQchart->addAxis(MemoryAxisY , Qt::AlignLeft);
    MemoryAxisX->setTickCount(5);
    MemoryAxisX->setRange(0 , MAXN);
    MemoryAxisY->setTickCount(2);
    MemoryAxisY->setRange(0 , 100);
    MemorySeries = new QSplineSeries(this);
    MemoryQchart->addSeries(MemorySeries);
    MemoryQchart->setTitle("Memory Usage Curve");
    MemorySeries->attachAxis(MemoryAxisX);
    MemorySeries->attachAxis(MemoryAxisY);
    MemoryChartView->setChart(MemoryQchart);
    ui->setMemoryUsageCurve->addWidget(MemoryChartView);
    CNTMemory = 0;
}

void systemMonitor::updateUsage(){
    updateSystemMessage();
    updateTime();
    updateCPUUsage();
    updateMemoryUsage();
    updateCPUInformation();
    updateProcess();
    updateCurrentTime();
    return ;

}
void systemMonitor::processInputIsNotInt(){
    QMessageBox::warning(this , tr("warning") , tr("The input is not a integer!"),QMessageBox::Yes);
    return ;
}
bool systemMonitor::checkQStringIsInteger(QString &s){
    string str = s.trimmed().toStdString();
    for(auto c : str){
        if(c < '0' || c > '9') return false;
    }
    return true;
}

void systemMonitor::clickShutDownProcess(){
    QString inputInteger = ui->inputPIDToShutDown->toPlainText();
    if(!checkQStringIsInteger(inputInteger)){
        processInputIsNotInt();
        return ;
    }
    int pid = inputInteger.trimmed().toInt();
    string killCommend = "kill -l " + std::to_string(pid);
    system(killCommend.data());
    return ;
}

void systemMonitor::clickFindProcess(){
    QString inputInteger = ui->inputPIDToFind->toPlainText();
    if(!checkQStringIsInteger(inputInteger)){
        processInputIsNotInt();
        return ;
    }
    int pid = inputInteger.trimmed().toInt();
    cout << pid << endl;
    QFile qFile;
    qFile.setFileName("/proc/" + QString::number(pid , 10) + "/stat");
    if(!qFile.open(QIODevice::ReadOnly)){
        processOpenFileError();
        return ;
    }
    QString s = qFile.readLine();
    if(s.size() == 0) return;
    s.replace('(' , ' ');
    stringstream text(s.toStdString());
    string t;
    text >> t;
    QString processName;//1
    while(true){
        text >> t;
        bool check = false;
        if(t.back() == ')'){
            check = true;
            t.pop_back();
        }
        processName.append(QString::fromStdString(t));
        if(check) break;
    }
    text >> t;
    QString processState = QString::fromStdString(t);//2
    text >> t;
    QString ppidOfProcess = QString::fromStdString(t);//3
    for(int i = 1 ; i <= 14 ; ++i) text >> t;
    QString processPriority = QString::fromStdString(t);//17
    for(int i = 1 ; i <= 5 ; ++i) text >> t;
    QString processMemory = QString::fromStdString(t);//22
    while(processName.length() < 60) processName.append(' ');
    QString res = "PID: " + QString::number(pid , 10) + "\n" + "PPID: " + ppidOfProcess +
            "\n" + "Process Name: " + processName + "\n" + "ProcessState: " + processState + "\n" +
            "Process Priority: " + processPriority + "\n" + "ProcessMemory: " + processMemory;
    qFile.close();
    QMessageBox::information(this , tr("Process Information") , tr(res.toStdString().data()),QMessageBox::Yes);
    return ;
}

void systemMonitor::clickShutDown(){
    system("shutdown -h now");
    return ;
}

void systemMonitor::processOpenFileError(std::string str){
    QMessageBox::warning(this , tr("warning") , tr(str.data()),QMessageBox::Yes);
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
                QString::number(ptm->tm_mday , 10) + " days " +
                QString::number((ptm->tm_hour+8 ) % 24 , 10) + " hours " +
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

    updateMemoryUsageCurve(used * 100.0 / total);
    qFile.close();
}
void systemMonitor::updateMemoryUsageCurve(double val){
    if(CNTMemory == 0) MemoryYList.append(val);
    CNTMemory = (CNTMemory + 1) % 100;
    if(MemoryYList.length() > MAXN) MemoryYList.removeFirst();
    QList<QPointF>points;
    points.clear();
    for(int i = 0 ; i < MemoryYList.length() ; ++i) points.append(QPointF(i , MemoryYList.at(i)));
    MemorySeries->replace(points);
    return ;
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
    QFile qFile;
    qFile.setFileName("/proc/stat");
    if(!qFile.open(QIODevice::ReadOnly)){
        processOpenFileError();
        return ;
    }
    vector<vector<int>>cpuTime(4 , vector<int>(7 , 0));
    for(int i = 0 ; i < 4 ; ++i){
        QString s = qFile.readLine();
        string t = s.toStdString();
        stringstream text(t);
        text >> t;
        for(int j = 0 ; j < 7 ; ++j){
            text >> t;
            s = QString::fromStdString(t);
            cpuTime[i][j] = s.trimmed().toInt();
        }
    }
    long long totalCPUTime = 0 , totalFreeCPUTime = 0;
    for(int i = 0 ; i < 4 ; ++i){
        for(int j = 0 ; j < 7 ; ++j) totalCPUTime += cpuTime[i][j];
        totalFreeCPUTime += cpuTime[i][3];
    }
    double myCPUUsage = 1 - 1.0 * totalFreeCPUTime / totalCPUTime;
    ui->setCPUUsage->setValue(myCPUUsage * 100);

    updateCPUUsageCurve(myCPUUsage * 100);
    qFile.close();
    return ;
}
void systemMonitor::updateCPUUsageCurve(double val){
    if(CNTCPU == 0) CPUYList.append(val);
    CNTCPU = (CNTCPU + 1) % 100;
    if(CPUYList.length() > MAXN) CPUYList.removeFirst();
    QList<QPointF>points;
    points.clear();
    for(int i = 0 ; i < CPUYList.length() ; ++i) points.append(QPointF(i , CPUYList.at(i)));
    CPUSeries->replace(points);
    return ;
}

void systemMonitor::updateProcess(){
    QFile qFile;
    QDir qDir("/proc");
    QStringList qStringList = qDir.entryList();
    QString qString = qStringList.join("\n");
    int find_start = 3;
    QMap<QString , QString>qMap;
    while(true){
        int a = qString.indexOf("\n" , find_start);
        int b = qString.indexOf("\n" , a + 1);
        find_start = b;
        QString pidOfProcess = qString.mid(a + 1 , b - a - 1);//0
        bool check = true;
        int pid = pidOfProcess.toInt(&check , 10);
        pidOfProcess = QString::number(pid , 10);
        if(!check) break;
        qFile.setFileName("/proc/" + pidOfProcess + "/stat");
        if(!qFile.open(QIODevice::ReadOnly)){
            processOpenFileError();
            return ;
        }
        QString s = qFile.readLine();
        if(s.size() == 0) break;
        s.replace('(' , ' ');
        stringstream text(s.toStdString());
        string t;
        text >> t;
        QString processName;//1
        while(true){
            text >> t;
            check = false;
            if(t.back() == ')'){
                check = true;
                t.pop_back();
            }
            processName.append(QString::fromStdString(t));
            if(check) break;
        }
        text >> t;
        QString processState = QString::fromStdString(t);//2
        text >> t;
        QString ppidOfProcess = QString::fromStdString(t);//3
        for(int i = 1 ; i <= 14 ; ++i) text >> t;
        QString processPriority = QString::fromStdString(t);//17
        for(int i = 1 ; i <= 5 ; ++i) text >> t;
        QString processMemory = QString::fromStdString(t);//22
        while(processName.length() < 60) processName.append(' ');
        QString res = pidOfProcess + "\t" + ppidOfProcess + "\t" + processName + "\t" + processState + "\t" + processPriority + "\t" + processMemory;
        qMap[processName.trimmed()] = res;
        qFile.close();
    }

    for(auto item  = qMap.begin(); item != qMap.end() ; ++item){
        if(mapString.count(item.key()) == 1 && mapString[item.key()] == item.value())  continue;
        if(map.count(item.key()) == 1) {
            int index = ui->listWidgetProcess->row(map[item.key()]);
            ui->listWidgetProcess->takeItem(index);
        }
        map[item.key()] = new QListWidgetItem(item.value() , ui->listWidgetProcess);
    }
    for(auto item = mapString.begin() ; item != mapString.end() ; ++item){
        if(qMap.count(item.key())) continue;
        int index = ui->listWidgetProcess->row(map[item.key()]);
        ui->listWidgetProcess->takeItem(index);
        map.remove(item.key());
    }
    mapString = qMap;
    int totalProcess = map.size();
    ui->setTotal->setText(QString::number(totalProcess , 10));
    return ;
}

void systemMonitor::updateCurrentTime(){
    time_t curTime = 0;
    struct tm* ptm = nullptr;
    time(&curTime);
    ptm = gmtime(&curTime);

    QString s = QString::number(ptm->tm_year + 1900 , 10) + " years " +
                QString::number(ptm->tm_mon + 1 , 10) + " month " +
                QString::number(ptm->tm_mday , 10) + " days " +
                QString::number((ptm->tm_hour+8 ) % 24 , 10) + " hours " +
                QString::number(ptm->tm_min , 10) + " minutes " +
                QString::number(ptm->tm_sec , 10) + " seconds";
    ui->setCurrentTime->setText(s);
    return ;
}


