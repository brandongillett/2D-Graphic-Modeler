#include "canvas.h"
#include "ui_canvas.h"
#include <QPainter>
#include "parser.h"
canvas::canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::canvas)
{
    ui->setupUi(this);
}

canvas::~canvas()
{
    delete ui;
}

void canvas::paintEvent(QPaintEvent*){
    QPainter painter(this);
    if (shapeselect=="Rectangle"){
        QPen pen(color);
        pen.setWidth(width);
        //pen.style(linestyle);
        QPoint p1;
        p1.setX(a);
        p1.setY(b);
        QPoint p2;
        p2.setX(c);
        p2.setY(d);
        painter.setPen(pen);
        painter.drawRect(QRect(a,b,c,d));
        //painter.drawRect(QRect(a,b,c,d));
    }
    if (shapeselect=="Line"){
        QPen pen(color);
        pen.setWidth(width);
        painter.setPen(pen);
        painter.drawLine(QLine(a,b,c,d));
    }
    if (shapeselect=="Ellipse"){
        QPen pen(color);
        pen.setWidth(width);
        painter.setPen(pen);
        painter.drawEllipse(QRect(a,b,c,d));
    }
    if (shapeselect=="PolyLine"){

    }
    if (shapeselect=="PolyGon"){
        QPolygon poly;
        poly << QPoint(a,b);
        poly << QPoint(c,d);
        poly << QPoint(e,f);
        poly << QPoint(g,h);
        QPen pen(color);
        pen.setWidth(width);
        painter.setPen(pen);
        painter.drawPolygon(poly);
    }
    if (shapeselect=="Text"){
        QPen pen(color);
        pen.setWidth(width);
        painter.setPen(pen);
        painter.drawText(QPoint(a,b),textn);

    }

}
void canvas::rec(int x, int y, int b2, int h,QString col, int wi, QString ls,QString shape)
{
    a = x;
    b = y;
    c = b2;
    d = h;
    color = col;
    width = wi;
    linestyle = ls;
    shapeselect = shape;
    update();
}

void canvas::linee(int x1, int y1, int x2, int y2,QString col, int wi, QString ls,QString shape){
    a = x1;
    b = y1;
    c = x2;
    d = y2;
    color = col;
    width = wi;
    linestyle = ls;
    shapeselect = shape;
    update();
}

void canvas::el(int x1, int y1, int x2, int y2,QString col, int wi, QString ls,QString shape){
    a = x1;
    b = y1;
    c = x2;
    d = y2;
    color = col;
    width = wi;
    linestyle = ls;
    shapeselect = shape;
    update();
}

void canvas::plinee(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4,QString col, int wi, QString ls,QString shape){
    a = x1;
    b = y1;
    c = x2;
    d = y2;
    e = x3;
    f = y3;
    g = x4;
    h = y4;
    color = col;
    width = wi;
    linestyle = ls;
    shapeselect = shape;
    update();
}

void canvas::pgon(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4,QString col, int wi, QString ls,QString shape){
    a = x1;
    b = y1;
    c = x2;
    d = y2;
    e = x3;
    f = y3;
    g = x4;
    h = y4;
    color = col;
    width = wi;
    linestyle = ls;
    shapeselect = shape;
    update();
}

void canvas::txt(int x, int y,QString col, int wi, QString ls,QString shape,QString text){
    textn = text;
    a = x;
    b = y;
    color = col;
    width = wi;
    linestyle = ls;
    shapeselect = shape;
    update();
}

void canvas::refresh(){
    shapeselect = "";
    update();
}
