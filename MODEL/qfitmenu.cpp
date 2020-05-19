#include "qfitmenu.h"
#include "qfitedit.h"
#include "qfitwindow.h"
#include <QLabel>
#include <QStringList>
#include <QPushButton>
#include <QIcon>
#include <QSize>
#include <QMessageBox>

Qfitmenu::Qfitmenu(Dlista<Workout*>& _WL,ModelWorkout& _m, XMLHandler& _XMLWorkout ,QWidget *_parent) : WL(_WL),m(_m), XMLWorkout(_XMLWorkout) ,QWidget(_parent) {
    Qfitnew = new QPushButton(tr("Crea"));
    Qfitsave = new QPushButton(tr("Salva"));
    Qfitexport = new QPushButton(tr("Esporta"));
    connect(Qfitnew, &QPushButton::clicked, [=]() {
        ApriScelta();
    });
    connect(Qfitsave, &QPushButton::clicked, [=]() {
        SalvaFile();
    });

    QPixmap banner(":/utils/logoProg.png");
    title = new QLabel;
    title->setPixmap(banner.scaled(200,100)); //modificare in futuro
    title->setAlignment(Qt::AlignLeft);
    layout = new QHBoxLayout();
    layoutMenu = new QVBoxLayout();
    layoutMenu->addWidget(Qfitnew);
    layoutMenu->addWidget(Qfitsave);
    layoutMenu->addWidget(Qfitexport);
    // layout->setContentsMargins(100,100,100,100);
    layout->addWidget(title);
    layout->setAlignment(title, Qt::AlignLeft);

    layout->addLayout(layoutMenu);
    layoutMenu->setAlignment(Qt::AlignRight);
    //layout->insertStretch( -1, 1 );
    setLayout(layout);

    //layout->setMargin(0);
    //layout->setSpacing(0);
}

void Qfitmenu::ApriScelta() {
    QfitEdit* dialog = new QfitEdit(WL,m);

    dialog->exec();
    dialog->disconnect();
    delete dialog;
}

void Qfitmenu::SalvaFile() {

    XMLWorkout.FileWriter();


}