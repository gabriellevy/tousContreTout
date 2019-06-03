#include "universtout.h"
#include "../destinLib/perso.h"
#include "ui_univers.h"
#include "genhistdemarrage.h"

UniversTout::UniversTout(ModeAffichage modeAffichage,
                         QWidget *parent)
    : Univers(parent, modeAffichage)
{
    this->AppliquerTheme(QColor(180, 180, 210));

}

void UniversTout::GenererCaracs()
{
}

Hist* UniversTout::ExecuterGenerateurHistoire()
{
    m_Histoire = new Hist();
    m_GenHistoire = new GenHistDemarrage(m_Histoire);
    m_GenHistoire->GenererHistoire();
    return m_Histoire;
}
