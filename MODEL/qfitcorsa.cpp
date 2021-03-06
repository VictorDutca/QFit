#include "qfitcorsa.h"
#include <iostream>
#include <QMessageBox>
#include "corsa.h"
#include "qfitwindow.h"
#include "modelworkout.h"
#include "errhandler.h"

QfitCorsa::QfitCorsa(Dlista<Workout*>& _WL, ModelWorkout& _m, QWidget* parent) : WL(_WL), m(_m) ,QDialog(parent) {
    gbCorsa = new QGroupBox("Corsa");
    LayoutForm = new QVBoxLayout;
    MainLayout = new QVBoxLayout;
    Ldistanza = new QLabel;
    Ldurata = new QLabel;
    Lpianura = new QLabel;
    Lsalita = new QLabel;
    Ldiscesa = new QLabel;
    Tdistanza = new QLineEdit;
    Tdurata = new QLineEdit;
    Tpianura = new QLineEdit;
    Tsalita = new QLineEdit;
    Tdiscesa = new QLineEdit;
    salva = new QPushButton;
    reset = new QPushButton;
    Hdistanza = new QHBoxLayout;
    Hdurata = new QHBoxLayout;
    Hpianura = new QHBoxLayout;
    Hsalita = new QHBoxLayout;
    Hdiscesa = new QHBoxLayout;
    Hbottoni = new QHBoxLayout;

    TitleLayoutCorsa = new QHBoxLayout;
    LBTcorsa = new QLabel(tr("Nuovo Corsa"));

    connect(salva, &QPushButton::clicked, [=]() {
        SalvaCorsa();
    });

    connect(reset, &QPushButton::clicked, [=]() {
        Reset();
    });

    Ldistanza->setText("Distanza:");
    Ldurata->setText("Durata:");
    Lpianura->setText("Pianura:");
    Lsalita->setText("Salita:");
    Ldiscesa->setText("Discesa:");

    Tdurata->setFixedWidth(350);
    Tdistanza->setFixedWidth(350);
    Tpianura->setFixedWidth(350);
    Tsalita->setFixedWidth(350);
    Tdiscesa->setFixedWidth(350);

    Hdistanza->addWidget(Ldistanza);
    Hdistanza->addWidget(Tdistanza);

    Hdurata->addWidget(Ldurata);
    Hdurata->addWidget(Tdurata);

    Hpianura->addWidget(Lpianura);
    Hpianura->addWidget(Tpianura);

    Hsalita->addWidget(Lsalita);
    Hsalita->addWidget(Tsalita);

    Hdiscesa->addWidget(Ldiscesa);
    Hdiscesa->addWidget(Tdiscesa);

    LayoutForm->addLayout(Hdistanza);
    LayoutForm->addLayout(Hdurata);
    LayoutForm->addLayout(Hpianura);
    LayoutForm->addLayout(Hsalita);
    LayoutForm->addLayout(Hdiscesa);

    salva->setText("Salva");
    reset->setText("Reset");
    Hbottoni->addWidget(salva);
    Hbottoni->addWidget(reset);

    gbCorsa->setLayout(LayoutForm);

    setWindowTitle(tr("QFit"));
    setWindowIcon(QIcon(":/utils/small_icon.png"));

    setFixedSize(500,250);

    TitleLayoutCorsa->addWidget(LBTcorsa, Qt::AlignCenter);
    LBTcorsa->setAlignment(Qt::AlignCenter);
    MainLayout->addLayout(TitleLayoutCorsa);

    MainLayout->addWidget(gbCorsa);
    MainLayout->addLayout(Hbottoni);
    setLayout(MainLayout);
}

void QfitCorsa::SalvaCorsa() {
    try {
        QString Odistanza = Tdistanza->text();
        int x1 = Odistanza.toInt();

        QString Odurata = Tdurata->text();
        int x2 = Odurata.toInt();

        QString Opianura = Tpianura->text();
        int x3 = Opianura.toInt();

        QString Odiscesa = Tdiscesa->text();
        int x4 = Odiscesa.toInt();

        QString Osalita = Tsalita->text();
        int x5 = Osalita.toInt();

        if(!x1 || !x2 || !x3 || !x4 || !x5) {
            throw ErrEmptyForm();
        }
        Workout *w = new Corsa(x2, x1, x3, x5, x4);
        Workout *wLast = WL.checkLast();
        if(*w == *wLast){

            QMessageBox msgBox;
            msgBox.setText("Il Workout è identico ad uno appena inserito! \nSi prega di cambiarlo.");
            msgBox.exec();

        }else{
        WL.pushT(w);
        m.update();
        close();
        }

    }
    catch(ErrEmptyForm) {
        QMessageBox msgBox;
        msgBox.setText("Dati non corretti.");
        msgBox.exec();
    }
}

void QfitCorsa::Reset() {
    Tdistanza->setText("");
    Tdurata->setText("");
    Tpianura->setText("");
    Tdiscesa->setText("");
    Tsalita->setText("");
}
