#ifndef GENHISTDEMARRAGE_H
#define GENHISTDEMARRAGE_H

#include "../destinLib/genhistoire.h"

/**
 * @brief Générateur de la phase de sélection de personnage et d'aventure
 */
class GenHistDemarrage : public GenHistoire
{
private:
    void GenererEvtsAccueil();
    virtual void GenererPersos();
    virtual void GenererFonctionsCallback();

public:
    GenHistDemarrage(Hist* histoireGeneree);

    virtual Hist* GenererHistoire();
};

#endif // GENHISTDEMARRAGE_H
