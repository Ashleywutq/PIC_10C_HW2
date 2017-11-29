#ifndef GRADECALCULATOR_H
#define GRADECALCULATOR_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class GradeCalculator;
}

class GradeCalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit GradeCalculator(QWidget *parent = 0);
    ~GradeCalculator();
    void updateA();
    void updateB();

public slots:
    void updatescore();

private:
    Ui::GradeCalculator *ui;
    QTimer * timer=nullptr;
};

#endif // GRADECALCULATOR_H
