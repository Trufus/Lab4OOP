#ifndef CLOCKS_H
#define CLOCKS_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QCheckBox>
#include <QWidget>
#include "datetime.h"

class Clocks : public QWidget
{
    Q_OBJECT
    DateTime DT;
    QLabel *inf;
    QTimer *Timer;
    QCheckBox *Shower;
    QCheckBox *Starter;
public:
    Clocks(QWidget *parent = 0);
    ~Clocks();
public slots:
    void hider();
    void launcher();
    void count();
    //void ();
};

#endif // CLOCKS_H
