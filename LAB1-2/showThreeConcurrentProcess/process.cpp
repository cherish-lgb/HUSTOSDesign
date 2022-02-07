#include "process.h"
#include "ui_Process.h"
#include <unistd.h>
#include <QTimer>

Process::Process(QWidget *parent , int x , int y):QWidget(parent) ,ui(new Ui::Process){
    ui->setupUi(this);
    this->setFixedSize(this->width() , this->height());
    this->move(x , y);
    int pid = getpid();
    ui->label_2->setText(QString::number(pid , 10));
    //QTimer* timer = new QTimer(this);
    //connect(timer , SIGNAL(timeout()) , this , SLOT(Update()));
    //timer->start(1000);
}
void Process::change(QString s){
    ui->label_4->setText(s);
    return ;
}

void Process::mySetText(QString s){
    ui->label_3->setText(s);
    return ;
}
void Process::Update(){

}

Process::~Process(){
    delete ui;
}

