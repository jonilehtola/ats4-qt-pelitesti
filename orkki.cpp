#include "orkki.h"
#include <stdlib.h>
#include <QLine>

orkki::orkki(QObject *i):QThread(i)
{
    sijainti = QPoint(std::rand() % 100, std::rand() % 100);
}


void orkki::liikuKohteeseen() {
    if (kohde.isNull() || sijainti == kohde) {
        kohde = QPoint(std::rand() % 100, std::rand() % 100);
    }
    QLineF siirtyma(sijainti, kohde);
    siirtyma.setLength(nopeus);
    sijainti.setX(sijainti.x() + siirtyma.dx() );
    sijainti.setY(sijainti.y() + siirtyma.dy() );

}
