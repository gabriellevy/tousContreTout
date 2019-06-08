#include "genhistdemarrage.h"

GenHistDemarrage::GenHistDemarrage(Hist* histoireGeneree):GenHistoire (histoireGeneree)
{

}void GenHistDemarrage::GenererFonctionsCallback()
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
    DPerso* peuple = new DPerso("temp_vide");
    IPerso::AjouterPersoJouable(peuple);
}

void GenHistDemarrage::GenererEvtsAccueil()
{
    Evt* Debut = this->AjouterEvt("Debut", "Test début Tous contre tous");
    /*Effet* intro =*/ this->m_GenerateurEvt->AjouterEffetNarration( Debut,
                "On va bientôt choisir notre personnage !");

}
