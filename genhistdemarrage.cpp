#include "genhistdemarrage.h"
#include "dpersotct.h"
#include <qglobal.h>

GenHistDemarrage::GenHistDemarrage(Hist* histoireGeneree):GenHistoire (histoireGeneree)
{
    qsrand(static_cast<unsigned int>(qrand()));
}

 void GenHistDemarrage::GenererFonctionsCallback()
{
    //m_HistoireGeneree->m_CallbackFunctions["appliquerCmdts"] = &appliquerCmdts;
}

Hist* GenHistDemarrage::GenererHistoire()
{
    GenererPersos();

    GenererFonctionsCallback();

    GenererEvtsAccueil();

    return m_HistoireGeneree;
}

void GenHistDemarrage::GenererPersos()
{
    DPerso* reveur = new DPerso("reveur", "Rêveur");
    IPerso::AjouterPersoJouable(reveur);

    DPersoTCT* batman = new DPersoTCT("batman", "Batman", "Le chavalier noir", ":/images/persos/batman.png",
                                      6, 6, 6, 4, 5, 3, 6);
    IPerso::AjouterPersoJouable(batman);
    m_TousLesPersos.push_back(batman);
}

void GenHistDemarrage::GenererEvtsAccueil()
{
    Evt* Debut = this->AjouterEvt("Debut", "Sélection du héros et de l'aventure");
    Effet* intro = this->m_GenerateurEvt->AjouterEffetNarration( Debut,
                "Choisissez votre personnage");
    // on tire 5 héros aléatoires parmi la liste et on les propose
    this->AjouterChoixPerso(Debut, intro);
    this->AjouterChoixPerso(Debut, intro);

}

Choix* GenHistDemarrage::AjouterChoixPerso(Evt* Debut, Effet* effet)
{
    DPersoTCT* perso = m_TousLesPersos.at(qrand() % m_TousLesPersos.length());
    QString changerPersoId = "devient" + perso->m_Id;

    Choix* choix = effet->AjouterChoixGoToEffet(perso->m_Nom, changerPersoId, perso->m_CheminImagePortrait);

    /*Effet* effet_change_perso =*/ this->m_GenerateurEvt->AjouterEffetChangementPerso(Debut, perso->m_Id, perso->m_Nom, perso->m_CheminImagePortrait, changerPersoId);

    this->m_GenerateurEvt->AjouterEffetNarration(Debut, "youpi youplalalal");

    return choix;
}
