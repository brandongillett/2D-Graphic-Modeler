#include "changeshape.h"
#include "ui_changeshape.h"

changeshape::changeshape(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeshape)
{
    ui->setupUi(this);
}

changeshape::~changeshape()
{
    delete ui;
}
