#include "clocks.h"
#include <QGridLayout>
#include <QVBoxLayout>



Clocks::Clocks(QWidget *parent)
{
    Starter = new QCheckBox(tr("Start"));
    Shower  = new QCheckBox(tr("Show"));
    inf = new QLabel(DT.toString());
    Timer = new QTimer;
    DateTime DT();
    //QLabel* L1 = new QLabel();
    //QLabel* L2 = new QLabel();

    connect(Timer, SIGNAL(timeout()), this, SLOT(count()));
    connect(Timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(Starter, SIGNAL(clicked()), this, SLOT(launcher()));
    connect(Shower, SIGNAL(clicked()), this, SLOT(hider()));
    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(inf);
    inf->hide();
    layout->addWidget(Starter);
    layout->addWidget(Shower);

    setLayout(layout);

    setWindowTitle(tr("Clocks"));
}

Clocks::~Clocks()
{

}

void Clocks::launcher()
{
    if (Starter->isChecked())
    {
        Timer->start(1000);
    }
    else
    {
        Timer->stop();
    }
}

void Clocks::count()
{
    DT++;
    inf->setText(DT.toString());
}

void Clocks::hider()
{
    if (Shower->isChecked())
    {
        inf->show();
    }
    else
    {
        inf->hide();
    }
}
