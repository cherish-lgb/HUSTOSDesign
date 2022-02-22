/********************************************************************************
** Form generated from reading UI file 'systemMonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMMONITOR_H
#define UI_SYSTEMMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_systemMonitor
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Process;
    QPushButton *shutDownProcess;
    QListWidget *listWidgetProcess;
    QLabel *Total;
    QLabel *setTotal;
    QTextEdit *inputPIDToFind;
    QPushButton *findProcess;
    QTextEdit *inputPIDToShutDown;
    QPushButton *shutDown;
    QWidget *Performance;
    QGroupBox *groupBox_3;
    QProgressBar *memoryUsage;
    QLabel *memoryTotal;
    QLabel *setMemoryTotal;
    QLabel *memoryUsed;
    QLabel *setMemoryUsed;
    QGroupBox *groupBox_4;
    QProgressBar *setCPUUsage;
    QGroupBox *groupBox_5;
    QLabel *setCurrentTime;
    QWidget *systemInformation;
    QGroupBox *groupBox;
    QLabel *hostName;
    QLabel *runingTime;
    QLabel *version;
    QLabel *setHostName;
    QLabel *setRunningTime;
    QLabel *setVersion;
    QLabel *startRunTime;
    QLabel *setStartRunTime;
    QGroupBox *groupBox_2;
    QLabel *numberOfCores;
    QLabel *CPUType;
    QLabel *setNumberOfCores;
    QLabel *setCPUType;
    QLabel *setDominantFrequency;
    QLabel *Hz;
    QWidget *tab;
    QGroupBox *groupBox_6;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *setCPUUsagesCurve;
    QWidget *tab_2;
    QGroupBox *groupBox_7;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *setMemoryUsageCurve;

    void setupUi(QMainWindow *systemMonitor)
    {
        if (systemMonitor->objectName().isEmpty())
            systemMonitor->setObjectName(QStringLiteral("systemMonitor"));
        systemMonitor->resize(966, 586);
        centralWidget = new QWidget(systemMonitor);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 951, 561));
        Process = new QWidget();
        Process->setObjectName(QStringLiteral("Process"));
        shutDownProcess = new QPushButton(Process);
        shutDownProcess->setObjectName(QStringLiteral("shutDownProcess"));
        shutDownProcess->setGeometry(QRect(790, 440, 141, 21));
        listWidgetProcess = new QListWidget(Process);
        listWidgetProcess->setObjectName(QStringLiteral("listWidgetProcess"));
        listWidgetProcess->setGeometry(QRect(15, 41, 651, 371));
        Total = new QLabel(Process);
        Total->setObjectName(QStringLiteral("Total"));
        Total->setGeometry(QRect(680, 100, 67, 17));
        setTotal = new QLabel(Process);
        setTotal->setObjectName(QStringLiteral("setTotal"));
        setTotal->setGeometry(QRect(850, 100, 67, 17));
        inputPIDToFind = new QTextEdit(Process);
        inputPIDToFind->setObjectName(QStringLiteral("inputPIDToFind"));
        inputPIDToFind->setGeometry(QRect(20, 430, 171, 41));
        findProcess = new QPushButton(Process);
        findProcess->setObjectName(QStringLiteral("findProcess"));
        findProcess->setGeometry(QRect(210, 440, 111, 25));
        inputPIDToShutDown = new QTextEdit(Process);
        inputPIDToShutDown->setObjectName(QStringLiteral("inputPIDToShutDown"));
        inputPIDToShutDown->setGeometry(QRect(520, 430, 141, 41));
        shutDown = new QPushButton(Process);
        shutDown->setObjectName(QStringLiteral("shutDown"));
        shutDown->setGeometry(QRect(840, 500, 89, 25));
        tabWidget->addTab(Process, QString());
        Performance = new QWidget();
        Performance->setObjectName(QStringLiteral("Performance"));
        groupBox_3 = new QGroupBox(Performance);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 40, 821, 161));
        memoryUsage = new QProgressBar(groupBox_3);
        memoryUsage->setObjectName(QStringLiteral("memoryUsage"));
        memoryUsage->setGeometry(QRect(0, 20, 821, 81));
        memoryUsage->setValue(24);
        memoryTotal = new QLabel(groupBox_3);
        memoryTotal->setObjectName(QStringLiteral("memoryTotal"));
        memoryTotal->setGeometry(QRect(10, 130, 101, 17));
        setMemoryTotal = new QLabel(groupBox_3);
        setMemoryTotal->setObjectName(QStringLiteral("setMemoryTotal"));
        setMemoryTotal->setGeometry(QRect(120, 130, 121, 17));
        memoryUsed = new QLabel(groupBox_3);
        memoryUsed->setObjectName(QStringLiteral("memoryUsed"));
        memoryUsed->setGeometry(QRect(480, 130, 101, 17));
        setMemoryUsed = new QLabel(groupBox_3);
        setMemoryUsed->setObjectName(QStringLiteral("setMemoryUsed"));
        setMemoryUsed->setGeometry(QRect(590, 130, 121, 17));
        groupBox_4 = new QGroupBox(Performance);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 230, 821, 161));
        setCPUUsage = new QProgressBar(groupBox_4);
        setCPUUsage->setObjectName(QStringLiteral("setCPUUsage"));
        setCPUUsage->setGeometry(QRect(0, 20, 821, 81));
        setCPUUsage->setValue(24);
        groupBox_5 = new QGroupBox(Performance);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 400, 821, 80));
        setCurrentTime = new QLabel(groupBox_5);
        setCurrentTime->setObjectName(QStringLiteral("setCurrentTime"));
        setCurrentTime->setGeometry(QRect(20, 30, 801, 41));
        tabWidget->addTab(Performance, QString());
        systemInformation = new QWidget();
        systemInformation->setObjectName(QStringLiteral("systemInformation"));
        groupBox = new QGroupBox(systemInformation);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 771, 191));
        hostName = new QLabel(groupBox);
        hostName->setObjectName(QStringLiteral("hostName"));
        hostName->setGeometry(QRect(20, 40, 81, 17));
        runingTime = new QLabel(groupBox);
        runingTime->setObjectName(QStringLiteral("runingTime"));
        runingTime->setGeometry(QRect(20, 120, 91, 17));
        version = new QLabel(groupBox);
        version->setObjectName(QStringLiteral("version"));
        version->setGeometry(QRect(20, 160, 81, 17));
        setHostName = new QLabel(groupBox);
        setHostName->setObjectName(QStringLiteral("setHostName"));
        setHostName->setGeometry(QRect(350, 40, 391, 17));
        setRunningTime = new QLabel(groupBox);
        setRunningTime->setObjectName(QStringLiteral("setRunningTime"));
        setRunningTime->setGeometry(QRect(350, 120, 391, 17));
        setVersion = new QLabel(groupBox);
        setVersion->setObjectName(QStringLiteral("setVersion"));
        setVersion->setGeometry(QRect(350, 160, 391, 17));
        startRunTime = new QLabel(groupBox);
        startRunTime->setObjectName(QStringLiteral("startRunTime"));
        startRunTime->setGeometry(QRect(20, 80, 111, 17));
        setStartRunTime = new QLabel(groupBox);
        setStartRunTime->setObjectName(QStringLiteral("setStartRunTime"));
        setStartRunTime->setGeometry(QRect(350, 80, 381, 17));
        groupBox_2 = new QGroupBox(systemInformation);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 240, 771, 211));
        numberOfCores = new QLabel(groupBox_2);
        numberOfCores->setObjectName(QStringLiteral("numberOfCores"));
        numberOfCores->setGeometry(QRect(20, 40, 121, 17));
        CPUType = new QLabel(groupBox_2);
        CPUType->setObjectName(QStringLiteral("CPUType"));
        CPUType->setGeometry(QRect(20, 100, 67, 17));
        setNumberOfCores = new QLabel(groupBox_2);
        setNumberOfCores->setObjectName(QStringLiteral("setNumberOfCores"));
        setNumberOfCores->setGeometry(QRect(350, 40, 381, 17));
        setCPUType = new QLabel(groupBox_2);
        setCPUType->setObjectName(QStringLiteral("setCPUType"));
        setCPUType->setGeometry(QRect(350, 100, 391, 17));
        setDominantFrequency = new QLabel(groupBox_2);
        setDominantFrequency->setObjectName(QStringLiteral("setDominantFrequency"));
        setDominantFrequency->setGeometry(QRect(350, 160, 401, 17));
        Hz = new QLabel(groupBox_2);
        Hz->setObjectName(QStringLiteral("Hz"));
        Hz->setGeometry(QRect(20, 160, 67, 17));
        tabWidget->addTab(systemInformation, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_6 = new QGroupBox(tab);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(20, 10, 811, 481));
        verticalLayoutWidget = new QWidget(groupBox_6);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 791, 441));
        setCPUUsagesCurve = new QVBoxLayout(verticalLayoutWidget);
        setCPUUsagesCurve->setSpacing(6);
        setCPUUsagesCurve->setContentsMargins(11, 11, 11, 11);
        setCPUUsagesCurve->setObjectName(QStringLiteral("setCPUUsagesCurve"));
        setCPUUsagesCurve->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_7 = new QGroupBox(tab_2);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(0, 10, 841, 481));
        verticalLayoutWidget_2 = new QWidget(groupBox_7);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(9, 29, 821, 441));
        setMemoryUsageCurve = new QVBoxLayout(verticalLayoutWidget_2);
        setMemoryUsageCurve->setSpacing(6);
        setMemoryUsageCurve->setContentsMargins(11, 11, 11, 11);
        setMemoryUsageCurve->setObjectName(QStringLiteral("setMemoryUsageCurve"));
        setMemoryUsageCurve->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab_2, QString());
        systemMonitor->setCentralWidget(centralWidget);

        retranslateUi(systemMonitor);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(systemMonitor);
    } // setupUi

    void retranslateUi(QMainWindow *systemMonitor)
    {
        systemMonitor->setWindowTitle(QApplication::translate("systemMonitor", "Process", Q_NULLPTR));
        shutDownProcess->setText(QApplication::translate("systemMonitor", "shut Down Process ", Q_NULLPTR));
        Total->setText(QApplication::translate("systemMonitor", "Total:", Q_NULLPTR));
        setTotal->setText(QApplication::translate("systemMonitor", "setTotal", Q_NULLPTR));
        findProcess->setText(QApplication::translate("systemMonitor", "Find Process", Q_NULLPTR));
        shutDown->setText(QApplication::translate("systemMonitor", "Shut Down", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Process), QApplication::translate("systemMonitor", "Process", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("systemMonitor", "Memory Usage", Q_NULLPTR));
        memoryTotal->setText(QApplication::translate("systemMonitor", "memoryTotal", Q_NULLPTR));
        setMemoryTotal->setText(QApplication::translate("systemMonitor", "setMemoryTotal", Q_NULLPTR));
        memoryUsed->setText(QApplication::translate("systemMonitor", "memoryUsed", Q_NULLPTR));
        setMemoryUsed->setText(QApplication::translate("systemMonitor", "setMemoryUsed", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("systemMonitor", "CPU Usage", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("systemMonitor", "Current Time", Q_NULLPTR));
        setCurrentTime->setText(QApplication::translate("systemMonitor", "setCurrentTime", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Performance), QApplication::translate("systemMonitor", "Performance", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("systemMonitor", "System Information", Q_NULLPTR));
        hostName->setText(QApplication::translate("systemMonitor", "hostName:", Q_NULLPTR));
        runingTime->setText(QApplication::translate("systemMonitor", "runningTime", Q_NULLPTR));
        version->setText(QApplication::translate("systemMonitor", "version", Q_NULLPTR));
        setHostName->setText(QApplication::translate("systemMonitor", "setHostName", Q_NULLPTR));
        setRunningTime->setText(QApplication::translate("systemMonitor", "setRunningTime", Q_NULLPTR));
        setVersion->setText(QApplication::translate("systemMonitor", "setVersion", Q_NULLPTR));
        startRunTime->setText(QApplication::translate("systemMonitor", "startRunTime", Q_NULLPTR));
        setStartRunTime->setText(QApplication::translate("systemMonitor", "setStartRunTime", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("systemMonitor", "CPU Information", Q_NULLPTR));
        numberOfCores->setText(QApplication::translate("systemMonitor", "Number of cores", Q_NULLPTR));
        CPUType->setText(QApplication::translate("systemMonitor", "CPUType", Q_NULLPTR));
        setNumberOfCores->setText(QApplication::translate("systemMonitor", "setNumberOfCores", Q_NULLPTR));
        setCPUType->setText(QApplication::translate("systemMonitor", "setCPUType", Q_NULLPTR));
        setDominantFrequency->setText(QApplication::translate("systemMonitor", "setDominantFrequency", Q_NULLPTR));
        Hz->setText(QApplication::translate("systemMonitor", "Hz", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(systemInformation), QApplication::translate("systemMonitor", "systemInformation", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("systemMonitor", "CPUUsageCurve", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("systemMonitor", "CPUUsageCurve", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("systemMonitor", "MemoryUsageCurve", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("systemMonitor", "MemoryUsageCurve", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class systemMonitor: public Ui_systemMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMMONITOR_H
