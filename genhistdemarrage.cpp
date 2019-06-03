#include "genhistdemarrage.h"

GenHistDemarrage::GenHistDemarrage(Hist* histoireGeneree):GenHistoire (histoireGeneree)
{

}void GenHistDemarrage::GenererFonctionsCallback()
{
    //m_HistoireGeneree->m_CallbackFunctions["appliquerCmdts"] = &appliquerCmdts;
}

void GenHistDemarrage::GenererThemes()
{

}

Hist* GenHistDemarrage::GenererHistoire()
{
    GenererThemes();

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
    /*Evt* Debut = AjouterEvt("Debut", "Test début 10 commandements");
    Effet* intro = Debut->AjouterEffetNarration(
                "On va bientôt choisir des commandements");
*/
}
