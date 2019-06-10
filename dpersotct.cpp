#include "dpersotct.h"

CompetencesTcT::CompetencesTcT(TypeCompetencesTcT TypeCompetencesTcT, int Val):m_TypeCompetencesTcT(TypeCompetencesTcT), m_Val(Val)
{}

DPersoTCT::DPersoTCT(QString id, QString nom, QString description, QString cheminImagePortrait,
                     int dexterite, int puissance, int agilete, int beaute, int intelligence, int sociabilite, int volonte)
    : DPerso (id, nom, description, cheminImagePortrait)
{
    m_Caracs[CaracTcT::EC_Dexterite] = dexterite;
    m_Caracs[CaracTcT::EC_Puissance] = puissance;
    m_Caracs[CaracTcT::EC_Agilete] = agilete;
    m_Caracs[CaracTcT::EC_Beaute] = beaute;
    m_Caracs[CaracTcT::EC_Intelligence] = intelligence;
    m_Caracs[CaracTcT::EC_Sociabilite] = sociabilite;
    m_Caracs[CaracTcT::EC_Volonte] = volonte;
}

void DPersoTCT::AjouterCompetence(TypeCompetencesTcT type_comp, int val)
{
    this->m_Competences.push_back(new CompetencesTcT(type_comp, val));
}

CaracTcT CompetencesTcT::GetCaracAssociee()
{
    switch (m_TypeCompetencesTcT) {
    //EC_Dexterite
    case TypeCompetencesTcT::Tir : return CaracTcT::EC_Dexterite;
    case TypeCompetencesTcT::Arme_blanche_legere : return CaracTcT::EC_Dexterite;
    case TypeCompetencesTcT::Crochetage : return CaracTcT::EC_Dexterite;
    case TypeCompetencesTcT::Instrument_Musique : return CaracTcT::EC_Dexterite;
    case TypeCompetencesTcT::Peinture : return CaracTcT::EC_Dexterite;
    case TypeCompetencesTcT::Lancer_de_projectiles : return CaracTcT::EC_Dexterite;
    case TypeCompetencesTcT::Conduite_Voiture : return CaracTcT::EC_Dexterite;
    case TypeCompetencesTcT::Pilotage : return CaracTcT::EC_Dexterite;
        //EC_Puissance
    case TypeCompetencesTcT::Combat_a_mains_nues : return CaracTcT::EC_Puissance;
    case TypeCompetencesTcT::Arme_blanche : return CaracTcT::EC_Puissance;
    case TypeCompetencesTcT::Archer : return CaracTcT::EC_Puissance;
    case TypeCompetencesTcT::Regeneration : return CaracTcT::EC_Puissance;
        //EC_Agilete
    case TypeCompetencesTcT::Bond : return CaracTcT::EC_Agilete;
    case TypeCompetencesTcT::Deltaplane : return CaracTcT::EC_Agilete;
    case TypeCompetencesTcT::Grappin : return CaracTcT::EC_Agilete;
        //EC_Beaute,
    case TypeCompetencesTcT::Sex_appeal : return CaracTcT::EC_Beaute;
        //EC_Intelligence,
    case TypeCompetencesTcT::Detective : return CaracTcT::EC_Intelligence;
    case TypeCompetencesTcT::Informatique : return CaracTcT::EC_Intelligence;
    case TypeCompetencesTcT::Scientifique : return CaracTcT::EC_Intelligence;
        //EC_Charisme,
    case TypeCompetencesTcT::Meneur_d_homme : return CaracTcT::EC_Sociabilite;
    case TypeCompetencesTcT::Empathie : return CaracTcT::EC_Sociabilite;
    case TypeCompetencesTcT::Seduction : return CaracTcT::EC_Sociabilite;
    case TypeCompetencesTcT::Marchandage : return CaracTcT::EC_Sociabilite;
    case TypeCompetencesTcT::Discours : return CaracTcT::EC_Sociabilite;
        //EC_Volonte
    case TypeCompetencesTcT::Miracles : return CaracTcT::EC_Volonte;
    }

    Q_ASSERT_X(true, "Type de carac associée à cette compétence non définie !", "CompetencesTcT::GetCaracAssociee");
    return CaracTcT::EC_Dexterite;
}
