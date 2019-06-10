#ifndef DPERSOTCT_H
#define DPERSOTCT_H

#include <QMap>
#include "../destinLib/perso.h"

enum TypeUnivers {
    TU_CombatHumain,
    TU_CombatSurhumain,
    TU_Scientifique,
    TU_VieDeTousLesJours,
    TU_Enquete,
    TU_Politique,
    TU_Militaire
};

enum CaracTcT {
    EC_Dexterite, // habileté manuelle
    EC_Puissance, // force / endurance /
    EC_Agilete,
    EC_Beaute,
    EC_Intelligence,
    EC_Sociabilite,
    EC_Volonte
    // int m_Perception;
};

// toutes les compétences existantes
enum TypeCompetencesTcT {
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
    Deltaplane,
    Grappin,
    //EC_Beaute,
    Sex_appeal,
    //EC_Intelligence,
    Detective,
    Informatique,
    Scientifique,
    Strategie,
    Tactique,
    Politique,
    //EC_Sociabilite,
    Meneur_d_homme,
    Empathie,
    Seduction,
    Marchandage,
    Discours,
    Poete,
    //EC_Volonte
    Miracles
};

struct CompetencesTcT {
    TypeCompetencesTcT m_TypeCompetencesTcT;
    int m_Val;

    CompetencesTcT(TypeCompetencesTcT TypeCompetencesTcT, int m_Val);

    CaracTcT GetCaracAssociee();
};

class DPersoTCT : public DPerso
{
public:
    DPersoTCT(QString id, QString nom, QString description, QString imagePortrait,
            int dexterite, int puissance, int agilete, int beaute, int intelligence, int sociabilite, int volonte);

    void AjouterCompetence(TypeCompetencesTcT comp, int val);

    QMap<CaracTcT, int> m_Caracs;
    QVector<CompetencesTcT*> m_Competences;
    QVector<TypeUnivers> m_TypeUnivers;
};

#endif // DPERSOTCT_H
