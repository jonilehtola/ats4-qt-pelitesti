#ifndef PELIMALLI_H
#define PELIMALLI_H

#include <QObject>
#include "orkki.h"

class Pelimalli : public QObject
{
    Q_OBJECT
    orkki *orc = nullptr;
public:
    explicit Pelimalli(QObject *parent = nullptr);
    void ammu(QPoint sijainti);
    void luoOrkki();

    std::list<orkki *> annaOrkit();
signals:
    void malliMuuttunut();

public slots:
    void orkkiMuuttunut();
};

#endif // PELIMALLI_H
