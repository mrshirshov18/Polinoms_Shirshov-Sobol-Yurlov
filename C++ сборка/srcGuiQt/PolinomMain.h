#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PolinomMain.h"

class PolinomMain : public QMainWindow
{
    Q_OBJECT

public:
    PolinomMain(QWidget *parent = nullptr);
    ~PolinomMain();

private:
    Ui::PolinomMainClass ui;

    enum POL_OP {POLINOMS_ADD, POLINOMS_SUBS, POLINOM_ADD_CONST, POLINOM_SUBS_CONST };

private slots:
    void slotRun(bool checked);
    void slotGuiNames(int Index);
};
