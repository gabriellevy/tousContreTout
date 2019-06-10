#ifndef DPERSOTCT_H
#define DPERSOTCT_H

#include <QMap>
#include "../destinLib/perso.h"

enum CaracTcT {
    EC_Dexterite, // habileté manuelle
    EC_Puissance, // force / endurance /
    EC_Agilete,
    EC_Beaute,
    EC_Intelligence,
    EC_Charisme,
    EC_Volonte
    // int m_Perception;
};

struct Competence {
    Carac m_CaracAssociee;
    int m_Val;
};


// toutes les compétences existantes
enum CompetencesTcT {
    //EC_Dexterite, // habileté manuelle
    Arme_blanche_legere,
    Tir,
    Crochetage,
    Instrument_Musique,
    Peinture,
    Lancer_de_projectiles,
    Conduite_Voiture,
    Pilotage,
    //EC_Puissance, // force / endurance /
    Combat_a_mains_nues,
    Arme_blanche,
    Archer,
    Regeneration,
    //EC_Agilete,
    Bond,
    //EC_Beaute,
    Sex_appeal,
    //EC_Intelligence,
    Detective,
    Informatique,
    Scientifique,
    //EC_Charisme,
    Meneur_d_homme,
    Empathie,
    Seduction,
    Marchandage,
    Discours,
    //EC_Volonte
    Miracles
};

class DPersoTCT : public DPerso
{
public:
    DPersoTCT(QString id, QString nom, QString description, QString imagePortrait,
            int dexterite, int puissance, int agilete, int beaute, int intelligence, int charisme, int volonte);

    QMap<CaracTcT, int> m_Caracs;
    QMap<CaracTcT, CompetencesTcT> m_Competences;
};

#endif // DPERSOTCT_H
