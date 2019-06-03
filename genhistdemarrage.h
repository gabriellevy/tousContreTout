#ifndef GENHISTDEMARRAGE_H
#define GENHISTDEMARRAGE_H

#include "../destinLib/genhistoire.h"

class GenHistDemarrage : public GenHistoire
{
private:
    void GenererEvtsAccueil();
    virtual void GenererPersos();
    virtual void GenererThemes();
    virtual void GenererFonctionsCallback();

public:
    GenHistDemarrage(Hist* histoireGeneree);

    virtual Hist* GenererHistoire();
};

#endif // GENHISTDEMARRAGE_H
