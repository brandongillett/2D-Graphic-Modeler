#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include "canvas.h"
#include "contact.h"
#include "shapes.h"
#include "parser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void LoggedIn(QString u);
    void LoggedOut();
    bool admin = false;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginbtn_clicked();

    void on_password_returnPressed();

    void on_pathbtn_clicked();

    void on_shapebox_currentTextChanged(const QString &arg1);

    void on_actionContact_Us_triggered();
private:
    Ui::MainWindow *ui;
    canvas* canvas;
    //myVector<shapes*> vec;
};
#endif // MAINWINDOW_H
