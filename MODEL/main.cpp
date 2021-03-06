#include <QApplication>
#include<iostream>
#include<typeinfo>
#include <vector>
#include "ciclismo.h"
#include "corsa.h"
#include "lista.h"
#include "nuoto.h"
#include "schedules.h"
#include "triathlon.h"
#include "workout.h"
#include "qfitwindow.h"
#include "xmlhandler.h"

int main(int argc, char *argv[])
{
    Dlista<Workout*> dlxml;
    XMLHandler caricatore(dlxml);
    caricatore.FileReader("QFitWorkout.xml");
    QApplication a(argc, argv);
    QFitWindow QfeetWindow(dlxml,caricatore);
    QfeetWindow.show();
    return a.exec();
}
