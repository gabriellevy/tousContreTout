#ifndef UNIVERSTOUT_H
#define UNIVERSTOUT_H

#include <QWidget>
#include "../destinLib/univers.h"
#include "genhistdemarrage.h"

class UniversTout : public Univers
{
    Q_OBJECT

public:
    UniversTout(ModeAffichage modeAffichage = ModeAffichage::ema_Jeu,
                QWidget *parent = nullptr);

    Hist* ExecuterGenerateurHistoire();

protected:
    // génère toutes les caracs qui peuvent être visualisées par le joueur (d'autres caracs peuvent être générées et invisibles n'importe quand dans l'aventure)
    virtual void GenererCaracs();

};

#endif // UNIVERSTOUT_H
