#ifndef SYSTEMMONITOR_H
#define SYSTEMMONITOR_H

#include<QWidget>
#include<QListWidget>
#include<QListWidgetItem>
#include<QStringList>
#include<QFile>
#include<QDir>
#include<QTimer>
#include<QLabel>
#include<QMessageBox>
#include<iostream>
#include<sstream>
#include<fstream>
#include<unistd.h>
#include<QMainWindow>
namespace Ui {
class systemMonitor;
}
class systemMonitor: public QMainWindow{
    Q_OBJECT
private:
    Ui::systemMonitor* ui;
    QTimer* timer;
    void updateProc(int pid);

    void updateCPUUsage();

    void updateMemoryUsage();

    void updateSystemMessage();

    void updateCPUInformation();

    void updateProcess();

    void updateTime();

    void showStartTime();

    void processOpenFileError();
public:
    explicit systemMonitor(QMainWindow* parent1 = nullptr);
public slots:
    void updateUsage();
};

#endif // SYSTEMMONITOR_H

