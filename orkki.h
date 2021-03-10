#ifndef ORKKI_H
#define ORKKI_H

#include <QPoint>
#include <QThread>

class orkki : public QThread
{
    Q_OBJECT


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

signals:
    void muuttunut();
};

#endif // ORKKI_H
