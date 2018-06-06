#include "aboutview.h"

CAboutView::CAboutView(QWidget *parent) : QWidget(parent)
{
    m_pTextField = new QLabel("Smart Home Easy Maker\n"
                              "SmHoEzMa\n\n"
                              "Created by\n"
                              " - Tobias Rieß\n"
                              " - Karl-Erik Kley\n"
                              " - Martin Lesser\n", this);

    m_pMainLayout = new QHBoxLayout();

    m_pMainLayout->addWidget(m_pTextField);

    setLayout(m_pMainLayout);
}
