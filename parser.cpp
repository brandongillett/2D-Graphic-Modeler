#include "parser.h"
rectangle *rec;
line *lin;
ellipse *elli;
polyline *polylin;
polygon *polygn;
text *txt;
void parse(QString path,Ui::MainWindow* ui)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);
    QString lineread;
    while(!in.atEnd()) {
        lineread = in.readLine();
        if (lineread == "Rectangle"){
            rec = new rectangle;
            rec->name = lineread;
            lineread = in.readLine();
            rec->id = lineread.toInt();
            lineread = in.readLine();
            QStringList text = lineread.split(',');
            rec->x = text[0].toInt();
            rec->y = text[1].toInt();
            rec->b = text[2].toInt();
            rec->h = text[3].toInt();
            lineread = in.readLine();
            rec->pcolor = lineread;
            lineread = in.readLine();
            rec->pwidth = lineread.toInt();
            lineread = in.readLine();
            rec->pstyle = lineread;
            //v.push_back(shape);
            ui->shapebox->addItem(rec->name);
            //canvas->setrec(rec);
        }
        else if (lineread == "Line"){
            lin = new line;
            lin->name = lineread;
            lineread = in.readLine();
            lin->id = lineread.toInt();
            lineread = in.readLine();
            QStringList text = lineread.split(',');
            lin->x1 = text[0].toInt();
            lin->y1 = text[1].toInt();
            lin->x2 = text[2].toInt();
            lin->y2 = text[3].toInt();
            lineread = in.readLine();
            lin->pcolor = lineread;
            lineread = in.readLine();
            lin->pwidth = lineread.toInt();
            lineread = in.readLine();
            lin->pstyle = lineread;
            ui->shapebox->addItem(lin->name);
        }
        else if (lineread == "Ellipse"){
            elli = new ellipse;
            elli->name = lineread;
            lineread = in.readLine();
            elli->id = lineread.toInt();
            lineread = in.readLine();
            QStringList text = lineread.split(',');
            elli->x1 = text[0].toInt();
            elli->y1 = text[1].toInt();
            elli->x2 = text[2].toInt();
            elli->y2 = text[3].toInt();
            lineread = in.readLine();
            elli->pcolor = lineread;
            lineread = in.readLine();
            elli->pwidth = lineread.toInt();
            lineread = in.readLine();
            elli->pstyle = lineread;
            ui->shapebox->addItem(elli->name);
        }
        else if (lineread == "PolyLine"){
            polylin = new polyline;
            polylin->name = lineread;
            lineread = in.readLine();
            polylin->id = lineread.toInt();
            lineread = in.readLine();
            QStringList text = lineread.split(',');
            polylin->x1 = text[0].toInt();
            polylin->y1 = text[1].toInt();
            polylin->x2 = text[2].toInt();
            polylin->y2 = text[3].toInt();
            polylin->x3 = text[4].toInt();
            polylin->y3 = text[5].toInt();
            polylin->x4 = text[6].toInt();
            polylin->y4 = text[7].toInt();
            lineread = in.readLine();
            polylin->pcolor = lineread;
            lineread = in.readLine();
            polylin->pwidth = lineread.toInt();
            lineread = in.readLine();
            polylin->pstyle = lineread;
            ui->shapebox->addItem(polylin->name);
        }
        else if (lineread == "PolyGon"){
            polygn = new polygon;
            polygn->name = lineread;
            lineread = in.readLine();
            polygn->id = lineread.toInt();
            lineread = in.readLine();
            QStringList text = lineread.split(',');
            polygn->x1 = text[0].toInt();
            polygn->y1 = text[1].toInt();
            polygn->x2 = text[2].toInt();
            polygn->y2 = text[3].toInt();
            polygn->x3 = text[4].toInt();
            polygn->y3 = text[5].toInt();
            polygn->x4 = text[6].toInt();
            polygn->y4 = text[7].toInt();
            lineread = in.readLine();
            polygn->pcolor = lineread;
            lineread = in.readLine();
            polygn->pwidth = lineread.toInt();
            lineread = in.readLine();
            polygn->pstyle = lineread;
            ui->shapebox->addItem(polygn->name);
        }
        else if (lineread == "Text"){
            txt = new text;
            txt->name = lineread;
            lineread = in.readLine();
            txt->id = lineread.toInt();
            lineread = in.readLine();
            QStringList text = lineread.split(',');
            txt->x = text[0].toInt();
            txt->y = text[1].toInt();
            lineread = in.readLine();
            txt->pcolor = lineread;
            lineread = in.readLine();
            txt->pwidth = lineread.toInt();
            lineread = in.readLine();
            txt->text = lineread;
            lineread = in.readLine();
            txt->pstyle = lineread;
            ui->shapebox->addItem(txt->name);
        }
    }

    file.close();
}

void setr(canvas* canvas,QString shape){
    canvas->rec(rec->x,rec->y,rec->b,rec->h,rec->pcolor,rec->pwidth,rec->pstyle,shape);
}
void setl(canvas* canvas,QString shape){
    canvas->linee(lin->x1,lin->y1,lin->x2,lin->y2,lin->pcolor,lin->pwidth,lin->pstyle,shape);
}
void sete(canvas* canvas,QString shape){
    canvas->linee(elli->x1,elli->y1,elli->x2,elli->y2,elli->pcolor,elli->pwidth,elli->pstyle,shape);
}
void setpl(canvas* canvas,QString shape){
    canvas->plinee(polylin->x1,polylin->y1,polylin->x2,polylin->y2,polylin->x3,polylin->y3,polylin->x4,polylin->y4,polylin->pcolor,polylin->pwidth,polylin->pstyle,shape);
}
void setpg(canvas* canvas,QString shape){
    canvas->pgon(polygn->x1,polygn->y1,polygn->x2,polygn->y2,polygn->x3,polygn->y3,polygn->x4,polygn->y4,polygn->pcolor,polygn->pwidth,polygn->pstyle,shape);
}
void sett(canvas* canvas,QString shape){
    canvas->txt(txt->x,txt->y,lin->pcolor,lin->pwidth,lin->pstyle,shape,txt->text);
}
void exitpro(){
    delete rec;
    delete lin;
}
