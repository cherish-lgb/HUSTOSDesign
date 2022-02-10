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
#include<QSet>
#include<QMap>
#include<QMainWindow>
#include<string>
namespace Ui {
class systemMonitor;
}
class systemMonitor: public QMainWindow{
    Q_OBJECT
private:
    Ui::systemMonitor* ui;
    QTimer* timer;
    QMap<QString , QListWidgetItem*>map;
    QMap<QString , QString>mapString;
    QSet<QString>set;
    void updateProc(int pid);

    void updateCPUUsage();

    void updateMemoryUsage();

    void updateSystemMessage();

    void updateCPUInformation();

    void updateProcess();

    void updateTime();

    void showStartTime();

    void processOpenFileError(std::string str = "The file can not open!");

    void updateCurrentTime();

    void processInputIsNotInt();

    bool checkQStringIsInteger(QString& s);
public:
    explicit systemMonitor(QMainWindow* parent1 = nullptr);
public slots:
    void updateUsage();
    void clickShutDownProcess();
    void clickFindProcess();
    void clickShutDown();
};

#endif // SYSTEMMONITOR_H

