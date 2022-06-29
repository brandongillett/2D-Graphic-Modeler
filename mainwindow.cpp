#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    canvas = ui->widget;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete canvas;
    exitpro();
}


void MainWindow::on_loginbtn_clicked()
{
    QString getbuttontxt = ui->loginbtn->text();
    if (getbuttontxt == "Sign In"){
        QString user = ui->username->text();
        QString pass = ui->password->text();
        if (user == "admin" && pass == "admin"){
            LoggedIn(user);
            admin = true;
        }
        else if (user == "user" && pass == "user"){
            LoggedIn(user);
        }
        else{
            QMessageBox msgbox;
            msgbox.setText("Incorrect Username Or Password!");
            msgbox.exec();
        }
    }
    else if(getbuttontxt == "Sign Out"){
        LoggedOut();
    }
}

void MainWindow::on_password_returnPressed()
{
    MainWindow::on_loginbtn_clicked();
}

void MainWindow::LoggedIn(QString u){
    //Sets Welcome Name To username
    ui->loginstatus->setText("Welcome : " + u);

    //Disables username and password text boxes and clears them
    ui->username->setEnabled(false);
    ui->password->setEnabled(false);
    ui->username->clear();
    ui->password->clear();

    //Sets Button Text to Signout
    ui->loginbtn->setText("Sign Out");

    //Enables all GraphicModeler Functions
    ui->pathbtn->setEnabled(true);
    ui->pathlbl->setEnabled(true);
    ui->pathtxt->setEnabled(true);
    ui->shapelbl->setEnabled(true);
    ui->shapebox->setEnabled(true);

    if (admin){
        ui->actionChange_Shapes_2->setEnabled(true);
    }

}

void MainWindow::LoggedOut(){
    //Sets Welcome Name To Logged Out
    ui->loginstatus->setText("Logged Out");

    //Enables username and password text boxes
    ui->username->setEnabled(true);
    ui->password->setEnabled(true);

    //Sets Button Text to Sing In
    ui->loginbtn->setText("Sign In");

    //Disables all Graphic Modeler Function
    ui->pathbtn->setEnabled(false);
    ui->pathlbl->setEnabled(false);
    ui->pathtxt->setEnabled(false);
    ui->shapelbl->setEnabled(false);
    ui->shapebox->setEnabled(false);
    ui->actionChange_Shapes_2->setEnabled(false);
}

void MainWindow::on_pathbtn_clicked()
{
    ui->shapebox->clear();
    ui->shapebox->addItem("Select Shape");
    QString filename;
    filename = QFileDialog::getOpenFileName(this, ("Select Shapes File"), "", tr("Text File (*.txt)"));
    ui->pathtxt->setText(filename);
    parse(filename,ui);
    canvas->refresh();
}

void MainWindow::on_shapebox_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Rectangle"){
        setr(canvas,arg1);
    }
    else if (arg1 == "Line"){
        setl(canvas,arg1);
    }
    else if (arg1 == "Ellipse"){
        sete(canvas,arg1);
    }
    else if (arg1 == "PolyLine"){
        setpl(canvas,arg1);
    }
    else if (arg1 == "PolyGon"){
        setpg(canvas,arg1);
    }
    else if (arg1 == "Text"){
        sett(canvas,arg1);
    }
    else{
        canvas->refresh();
    }
}

void MainWindow::on_actionContact_Us_triggered()
{
    contact c;
    c.exec();
}

