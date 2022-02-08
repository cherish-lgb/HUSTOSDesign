/********************************************************************************
** Form generated from reading UI file 'Process.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESS_H
#define UI_PROCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Process
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_1;
    QLabel *label_1;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;

    void setupUi(QWidget *Process)
    {
        if (Process->objectName().isEmpty())
            Process->setObjectName(QStringLiteral("Process"));
        Process->resize(361, 242);
        layoutWidget = new QWidget(Process);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 321, 201));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setSpacing(6);
        horizontalLayout_1->setObjectName(QStringLiteral("horizontalLayout_1"));
        label_1 = new QLabel(layoutWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setTextFormat(Qt::PlainText);

        horizontalLayout_1->addWidget(label_1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_1->addItem(horizontalSpacer);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_1->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_1);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Process);

        QMetaObject::connectSlotsByName(Process);
    } // setupUi

    void retranslateUi(QWidget *Process)
    {
        Process->setWindowTitle(QApplication::translate("Process", "Widget", Q_NULLPTR));
        label_1->setText(QApplication::translate("Process", "\345\275\223\345\211\215\350\277\233\347\250\213pid:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Process", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("Process", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("Process", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Process: public Ui_Process {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESS_H
