#include "PolinomMain.h"
#include "Polinom.h"

#include <Qstring>

PolinomMain::PolinomMain(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // Привязываем сигнал от кнопки на наш slot
    connect(ui.pbRun, &QPushButton::clicked, this, &PolinomMain::slotRun);
    // Привязываем сигнал от combobox на слот изменения значения
    connect(ui.cbOperation, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &PolinomMain::slotGuiNames);
}

PolinomMain::~PolinomMain()
{}


void PolinomMain::slotGuiNames(int Index)
{
    switch (Index)
    {
    case POLINOMS_ADD:
    case POLINOMS_SUBS:
        ui.lbOperand2->setText("Polinom2");
        break;
    case POLINOM_ADD_CONST:
    case POLINOM_SUBS_CONST:
        ui.lbOperand2->setText("Constant");
        break;
    }
}

void PolinomMain::slotRun(bool checked){

    // Полиномы создаются только через constructor, поэтому ни смог использовать switch
    if (ui.cbOperation->currentIndex() == POLINOMS_ADD) // Polinom + Polinom
    {
        Polinom p1( ui.edOp1->text().trimmed().toStdString() );
        Polinom p2( ui.edOp2->text().trimmed().toStdString() );
        Polinom pres = p1 + p2;
        QString sres = ui.edOp1->text().trimmed() + "+";
        sres += ui.edOp2->text().trimmed() + " = ";
        sres += QString(pres.GivePolinom().c_str());
        ui.teResult->append(sres);
    }
    else if (ui.cbOperation->currentIndex() == POLINOMS_SUBS) // Polinom - Polinom
    {
        Polinom p1(ui.edOp1->text().trimmed().toStdString());
        Polinom p2(ui.edOp2->text().trimmed().toStdString());
        Polinom pres = p1 - p2;
        QString sres = ui.edOp1->text().trimmed() + "-(";
        sres += ui.edOp2->text().trimmed() + ") = ";
        sres += QString(pres.GivePolinom().c_str());
        ui.teResult->append(sres);
    }
}
