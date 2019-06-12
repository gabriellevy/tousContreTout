#include "genhistdemarrage.h"
#include "dpersotct.h"
#include <QTime>
//#include <qglobal.h>

GenHistDemarrage::GenHistDemarrage(Hist* histoireGeneree):GenHistoire (histoireGeneree)
{
    QTime time = QTime::currentTime();
    qsrand(static_cast<uint>(time.msec()));
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
    batman->AjouterCompetence(TypeCompetencesTcT::Crochetage, 5);
    batman->AjouterCompetence(TypeCompetencesTcT::Lancer_de_projectiles, 6);
    batman->AjouterCompetence(TypeCompetencesTcT::Conduite_Voiture, 5);
    batman->AjouterCompetence(TypeCompetencesTcT::Pilotage, 5);
    batman->AjouterCompetence(TypeCompetencesTcT::Combat_a_mains_nues, 6);
    batman->AjouterCompetence(TypeCompetencesTcT::Deltaplane, 6);
    batman->AjouterCompetence(TypeCompetencesTcT::Grappin, 6);
    batman->AjouterCompetence(TypeCompetencesTcT::Detective, 6);
    batman->m_TypeUnivers.push_back(TypeUnivers::TU_Enquete);
    batman->m_TypeUnivers.push_back(TypeUnivers::TU_CombatHumain);
    batman->m_TypeUnivers.push_back(TypeUnivers::TU_CombatSurhumain);
    m_TousLesPersos.push_back(batman);

    DPersoTCT* rick = new DPersoTCT("rick", "Rick", "youpi", ":/images/persos/rick.jpg",
                                      5, 3, 3, 2, 10, 2, 5);
    IPerso::AjouterPersoJouable(rick);
    rick->AjouterCompetence(TypeCompetencesTcT::Scientifique, 6);
    //Pistolet à portails
    rick->m_TypeUnivers.push_back(TypeUnivers::TU_CombatSurhumain);
    rick->m_TypeUnivers.push_back(TypeUnivers::TU_Enquete);
    rick->m_TypeUnivers.push_back(TypeUnivers::TU_CombatHumain);
    rick->m_TypeUnivers.push_back(TypeUnivers::TU_Scientifique);
    rick->m_TypeUnivers.push_back(TypeUnivers::TU_VieDeTousLesJours);
    m_TousLesPersos.push_back(rick);

    DPersoTCT* herakles = new DPersoTCT("herakles", "Héraklès", "Le lion de l'olympe", ":/images/persos/Herakles.png",
                                      6, 9, 4, 3, 3, 3, 6);
    IPerso::AjouterPersoJouable(herakles);
    herakles->AjouterCompetence(TypeCompetencesTcT::Combat_a_mains_nues, 6);
    herakles->AjouterCompetence(TypeCompetencesTcT::Archer, 6);
    herakles->AjouterCompetence(TypeCompetencesTcT::Arme_blanche, 6);
    herakles->m_TypeUnivers.push_back(TypeUnivers::TU_CombatSurhumain);
    herakles->m_TypeUnivers.push_back(TypeUnivers::TU_CombatHumain);
    m_TousLesPersos.push_back(herakles);

    DPersoTCT* napoleon = new DPersoTCT("napoleon", "Napoléon", "", ":/images/persos/napoleon.jpg",
                                      3, 3, 3, 3, 5, 6, 6);
    IPerso::AjouterPersoJouable(napoleon);
    napoleon->AjouterCompetence(TypeCompetencesTcT::Strategie, 6);
    napoleon->AjouterCompetence(TypeCompetencesTcT::Tactique, 6);
    napoleon->AjouterCompetence(TypeCompetencesTcT::Politique, 6);
    napoleon->AjouterCompetence(TypeCompetencesTcT::Discours, 6);
    napoleon->m_TypeUnivers.push_back(TypeUnivers::TU_Enquete);
    napoleon->m_TypeUnivers.push_back(TypeUnivers::TU_CombatHumain);
    napoleon->m_TypeUnivers.push_back(TypeUnivers::TU_Politique);
    napoleon->m_TypeUnivers.push_back(TypeUnivers::TU_Militaire);
    m_TousLesPersos.push_back(napoleon);

    DPersoTCT* jesus = new DPersoTCT("jesus", "Jésus", "", ":/images/persos/jesus.jpg",
                                      3, 3, 3, 4, 3, 6, 10);
    IPerso::AjouterPersoJouable(jesus);
    jesus->AjouterCompetence(TypeCompetencesTcT::Politique, 6);
    jesus->AjouterCompetence(TypeCompetencesTcT::Discours, 6);
    jesus->AjouterCompetence(TypeCompetencesTcT::Miracles, 6);
    jesus->m_TypeUnivers.push_back(TypeUnivers::TU_Politique);
    jesus->m_TypeUnivers.push_back(TypeUnivers::TU_VieDeTousLesJours);
    m_TousLesPersos.push_back(jesus);


}

/**
 * génération de la pahse de choix de personnage
 */
void GenHistDemarrage::GenererEvtsAccueil()
{
    /*Evt* Debut = */this->AjouterEvt("Debut", "Sélection du héros et de l'aventure");
    Effet* intro =this->m_GenerateurEvt->AjouterEffetNarration( "Choisissez votre personnage");
    // on tire 5 héros aléatoires parmi la liste et on les propose
    this->AjouterChoixPerso(intro);
    this->AjouterChoixPerso(intro);
    this->AjouterChoixPerso(intro);
    this->AjouterChoixPerso(intro);
}

Choix* GenHistDemarrage::AjouterChoixPerso(Effet* effetChoix)
{
    DPersoTCT* perso = m_TousLesPersos.at(qrand() % m_TousLesPersos.length());
    QString changerPersoId = "devient" + perso->m_Id;

    Choix* choix = m_GenerateurEvt->AjouterChoixGoToEffet(perso->m_Nom, changerPersoId, perso->m_CheminImagePortrait, effetChoix);

    QString textChoix = "Vous êtes maintenant " + perso->m_Nom;
    this->m_GenerateurEvt->AjouterEffetChangementPerso(
                perso->m_Id, textChoix, perso->m_CheminImagePortrait, changerPersoId);

    this->m_GenerateurEvt->AjouterEffetNarration("youpi youplalalal");

    return choix;
}

/**
 * fin de génération de la phase de choix de personnage
 */
