#ifndef PELIMALLIWIDGET_H
#define PELIMALLIWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include "pelimalli.h"

class PelimalliWidget : public QWidget
{
    Q_OBJECT
    Pelimalli malli;
public:
    explicit PelimalliWidget(QWidget *parent = nullptr);


signals:

public slots:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void malliMuuttunut();
};

#endif // PELIMALLIWIDGET_H
