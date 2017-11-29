#include "gradecalculator.h"
#include "ui_gradecalculator.h"

GradeCalculator::GradeCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GradeCalculator)
{
    ui->setupUi(this);
    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(updatescore()));
    timer->start(500);
}

GradeCalculator::~GradeCalculator()
{
    delete ui;
}

void GradeCalculator::updatescore(){
    if (ui->radioButton->isChecked() == true) {
        updateA();
    }else if (ui->radioButton_2->isChecked() == true){
        updateB();
    }
    return;
}

void GradeCalculator::updateA(){
    double score=0;

    //add sum of hw scores
    double hw=0;
    hw+=ui->spinBox->value();
    hw+=ui->spinBox_2->value();
    hw+=ui->spinBox_3->value();
    hw+=ui->spinBox_4->value();
    hw+=ui->spinBox_5->value();
    hw+=ui->spinBox_6->value();
    hw+=ui->spinBox_7->value();
    hw+=ui->spinBox_8->value();
    score+=hw/8*0.25;
    score+=ui->spinBox_9->value()*0.2;
    score+=ui->spinBox_10->value()*0.2;
    score+=ui->spinBox_11->value()*0.35;

    ui->label_3->setText(QString::number(score));
    return;
}

void GradeCalculator::updateB(){
    double score=0;

    //add sum of hw scores
    double hw=0;
    hw+=ui->spinBox->value();
    hw+=ui->spinBox_2->value();
    hw+=ui->spinBox_3->value();
    hw+=ui->spinBox_4->value();
    hw+=ui->spinBox_5->value();
    hw+=ui->spinBox_6->value();
    hw+=ui->spinBox_7->value();
    hw+=ui->spinBox_8->value();
    score+=hw/8*0.25;

    if (ui->spinBox_9->value()>ui->spinBox_10->value()){
        score+=ui->spinBox_9->value()*0.3;
    }else{
        score+=ui->spinBox_10->value()*0.3;
    }
    score+=ui->spinBox_11->value()*0.45;

    ui->label_3->setText(QString::number(score));
    return;
}
