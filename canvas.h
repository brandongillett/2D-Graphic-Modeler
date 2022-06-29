#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

namespace Ui {
class canvas;
}

class canvas : public QWidget
{
    Q_OBJECT

public:
    explicit canvas(QWidget *parent = nullptr);
    ~canvas();
    void paintEvent(QPaintEvent*);
    void rec(int x, int y, int b, int h,QString col, int wi, QString ls,QString shape);
    void linee(int x1, int y1, int x2, int y2,QString col, int wi, QString ls,QString shape);
    void el(int x1, int y1, int x2, int y2,QString col, int wi, QString ls,QString shape);
    void plinee(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4,QString col, int wi, QString ls,QString shape);
    void pgon(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4,QString col, int wi, QString ls,QString shape);
    void txt(int x, int y,QString col, int wi, QString ls,QString shape,QString text);
    void refresh();
private:
    Ui::canvas *ui;
    QString shapeselect,textn;
    int a,b,c,d,e,f,g,h,width;
    QString color,linestyle;
};

#endif // CANVAS_H
