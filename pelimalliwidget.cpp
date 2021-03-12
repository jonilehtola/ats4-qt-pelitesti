#include "pelimalliwidget.h"
#include <QPainter>
#include <QDebug>

PelimalliWidget::PelimalliWidget(QWidget *parent) : QWidget(parent)
{
    connect(&malli, &Pelimalli::malliMuuttunut, this, &PelimalliWidget::malliMuuttunut);
}

void PelimalliWidget::malliMuuttunut() {
    qDebug()<<"reqp";

   repaint();

}

void PelimalliWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    //QPixmap *kuva = new QPixmap(this->width(), this->height());
    //QPainter kuvaPiirrin(kuva);
    for (auto const &i: *malli.annaOrkit()) {

        if (i == nullptr)
            continue;
        qDebug()<<"piirretään örkki";
        painter.drawEllipse(i->sijainti, 10, 10);
    }
}

void PelimalliWidget::mousePressEvent(QMouseEvent *evt) {
    malli.ammu(evt->pos());
}

void PelimalliWidget::luoOrkki() {
    malli.luoOrkki();
}
