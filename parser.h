#ifndef PARSER_H
#define PARSER_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

void parse(QString path,Ui::MainWindow *ui);
void setr(canvas* canvas,QString shape);
void setl(canvas* canvas,QString shape);
void sete(canvas* canvas,QString shape);
void setpl(canvas* canvas,QString shape);
void setpg(canvas* canvas,QString shape);
void sett(canvas* canvas,QString shape);
void exitpro();
#endif // PARSER_H
