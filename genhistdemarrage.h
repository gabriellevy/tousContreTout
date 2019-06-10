#ifndef GENHISTDEMARRAGE_H
#define GENHISTDEMARRAGE_H

#include "../destinLib/genhistoire.h"

class DPersoTCT;

/**
 * @brief Générateur de la phase de sélection de personnage et d'aventure
 */
class GenHistDemarrage : public GenHistoire
{
private:
    QVector<DPersoTCT*> m_TousLesPersos;

    void GenererEvtsAccueil();
    virtual void GenererPersos();
    virtual void GenererFonctionsCallback();

public:
    GenHistDemarrage(Hist* histoireGeneree);

    virtual Hist* GenererHistoire();

    Choix* AjouterChoixPerso(Evt* Debut, Effet* effet);
};

#endif // GENHISTDEMARRAGE_H
