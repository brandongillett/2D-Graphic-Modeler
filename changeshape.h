#ifndef CHANGESHAPE_H
#define CHANGESHAPE_H

#include <QDialog>

namespace Ui {
class changeshape;
}

class changeshape : public QDialog
{
    Q_OBJECT

public:
    explicit changeshape(QWidget *parent = nullptr);
    ~changeshape();

private:
    Ui::changeshape *ui;
};

#endif // CHANGESHAPE_H
