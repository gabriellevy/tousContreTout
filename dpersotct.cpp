#include "dpersotct.h"

DPersoTCT::DPersoTCT(QString id, QString nom, QString description, QString cheminImagePortrait,
                     int dexterite, int puissance, int agilete, int beaute, int intelligence, int charisme, int volonte)
    : DPerso (id, nom, description, cheminImagePortrait)
{
    m_Caracs[CaracTcT::EC_Dexterite] = dexterite;
    m_Caracs[CaracTcT::EC_Puissance] = puissance;
    m_Caracs[CaracTcT::EC_Agilete] = agilete;
    m_Caracs[CaracTcT::EC_Beaute] = beaute;
    m_Caracs[CaracTcT::EC_Intelligence] = intelligence;
    m_Caracs[CaracTcT::EC_Charisme] = charisme;
    m_Caracs[CaracTcT::EC_Volonte] = volonte;
}
