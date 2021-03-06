#ifndef QFITTRIATHLON_H
#define QFITTRIATHLON_H
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QLineEdit>
#include "lista.h"
#include "modelworkout.h"
#include <QGroupBox>

class QfitTriathlon : public QDialog {
Q_OBJECT
public:
    QfitTriathlon(Dlista<Workout*>& , ModelWorkout&,  QWidget* = nullptr);
private:
    QVBoxLayout *LayoutForm;
    QVBoxLayout *MainLayout;
    QLabel *COdistanza, *COdurata, *COpianura, *COsalita, *COdiscesa, *CIdistanza, *CIdurata, *CIpianura, *CIsalita, *CIdiscesa, *Ndurata, *Nrana, *Ndorso, *Nlibero, *LBTTriat;
    QLineEdit *TCOdistanza, *TCOdurata, *TCOpianura, *TCOsalita, *TCOdiscesa, *TCIdistanza, *TCIdurata, *TCIpianura, *TCIsalita, *TCIdiscesa, *TNdurata, *TNrana, *TNdorso, *TNlibero;
    QPushButton *salva, *reset;
    QHBoxLayout *HCOdistanza, *HCOdurata, *HCOpianura, *HCOsalita, *HCOdiscesa, *HCIdistanza, *HCIdurata, *HCIpianura, *HCIsalita, *HCIdiscesa, *HNdurata, *HNrana, *HNdorso, *HNlibero, *Hbottoni,*TitleLayout;
    Dlista<Workout*>& WL;
    ModelWorkout& m;
    QGroupBox *gbCorsa;
    QGroupBox *gbCiclismo;
    QGroupBox *gbNuoto;
    QVBoxLayout *LTCorsa, *LTCiclismo, *LTNuoto;
private slots:
    void SalvaTriathlon();
    void Reset();
};

#endif // QFITTRIATHLON_H
