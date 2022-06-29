#ifndef SHAPES_H
#define SHAPES_H
#include "mainwindow.h"

class shapes
{
public:
    shapes();
    int id;

};

class rectangle : public shapes
{
public:
    QString name,pcolor,pstyle;
    int x,y,b,h,pwidth;
};

class line : public shapes
{
public:
    QString name,pcolor,pstyle;
    int x1,y1,x2,y2,pwidth;
};

class polyline : public shapes
{
public:
    QString name,pcolor,pstyle;
    int x1,y1,x2,y2,x3,y3,x4,y4,pwidth;
};

class polygon : public shapes
{
public:
    QString name,pcolor,pstyle;
    int x1,y1,x2,y2,x3,y3,x4,y4,pwidth;
};


class ellipse : public shapes
{
public:
    QString name,pcolor,pstyle;
    int x1,y1,x2,y2,pwidth;
};

class text : public shapes
{
public:
    QString name,pcolor,pstyle,text;
    int x,y,pwidth;
};

#endif // SHAPES_H
