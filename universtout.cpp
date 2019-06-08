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
    return this->ExecuterGenerateurHistoire(HistoireId::hi_Selection);
}

Hist* UniversTout::ExecuterGenerateurHistoire(HistoireId histoireId)
{
    switch (histoireId) {
    case HistoireId::hi_Selection : {
        m_Histoire = new Hist("Sélection du rêve");
        m_GenHistoire = new GenHistDemarrage(m_Histoire);
        m_GenHistoire->GenererHistoire();
        this->setWindowTitle("Sélection du rêve");
    }break;
    }

    Q_ASSERT_X(m_Histoire != nullptr, "UniversTout::ExecuterGenerateurHistoire", "Génération d'histoire échouée");

    return m_Histoire;
}
