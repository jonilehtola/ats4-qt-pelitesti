#include "pelimalli.h"
#include <QLine>

Pelimalli::Pelimalli(QObject *parent) : QObject(parent)
{

}

void Pelimalli::luoOrkki() {
    orkki *uusiOrkki = new orkki(this);
    connect(uusiOrkki, &orkki::muuttunut, this, &Pelimalli::orkkiMuuttunut);
    // connect(uusiOrkki, &orkki::finished, uusiOrkki, &QObject::deleteLater);
    uusiOrkki->start();
}

void Pelimalli::orkkiMuuttunut() {
    emit malliMuuttunut();
}

void Pelimalli::ammu(QPoint s) {
    if (orc != nullptr) {
        if (QLineF(s, orc->sijainti).length() < 10) {
            orc->kuollut = true;
        }
    }
}

std::list<orkki*> Pelimalli::annaOrkit() {
    std::list<orkki*> lista;
    lista.push_back(orc);
}
