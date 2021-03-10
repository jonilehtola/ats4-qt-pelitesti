#ifndef ORKKI_H
#define ORKKI_H

#include <QPoint>
#include <QThread>

class orkki : public QThread
{
    Q_OBJECT

private:
    QPoint kohde;
    float nopeus = 1.0;

public:
    void run() override {
        while (!kuollut) {
            liikuKohteeseen();
            QThread::sleep(1000);
            emit muuttunut();
        }
    }

    orkki(QObject *i);
    QPoint sijainti;
    bool kuollut;

    void liikuKohteeseen();
signals:
    void muuttunut();
};

#endif // ORKKI_H
