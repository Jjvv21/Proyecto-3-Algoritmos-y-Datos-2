#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <iostream>
#include "Window.h"
#include <QMessageBox>
#include <QFileDialog>


/***
 * Creacion de la ventana
 * @param parent
 */
Window::Window(QWidget *parent) :
        QWidget(parent) {
    this->controller = Controller();
    setFixedSize(950, 500);
    this->setWindowTitle("TEC File System");
    layout = new QGridLayout(this);
    this->setLayout(layout);
    box1 = new QHBoxLayout();
    XML = new QPushButton("XML");
    TXT = new QPushButton("TXT");
    Buscador = new QLineEdit();
    Buscador->setPlaceholderText("Buscar Libro");
    Buscar = new QPushButton("Buscar");
    Lector = new QTextEdit();
    Lector->setReadOnly(true);
    box1->addWidget(XML,0,0);
    box1->addWidget(TXT,0,0);
    box1->addWidget(Buscador,0,0);
    box1->addWidget(Buscar,0,0);
    layout->addLayout(box1,0,0);
    layout->addWidget(Lector,1,0);

    connect(XML,SIGNAL(clicked()),this,SLOT(CargarXML()));
    connect(TXT,SIGNAL(clicked()),this,SLOT(AbrirTxT()));
    connect(Buscar,SIGNAL(clicked()),this,SLOT(BuscarLibro()));
}
void Window::CargarXML(){
    QUrl path = QFileDialog::getOpenFileUrl(this,
                                            tr("Select xml"),
                                            tr(""),
                                            tr("file (*.xml);;All Files (*)"));
}
void Window::AbrirTxT(){
    QUrl path = QFileDialog::getOpenFileUrl(this,
                                            tr("Select txt"),
                                            tr(""),
                                            tr("file (*.txt);;All Files (*)"));
    QString qpath = path.path();
    std::string realpath = qpath.toStdString();
    controller.addBook(realpath);
}
void Window::BuscarLibro() {
    QString mString;
    mString = Buscador->text();
    string Libro_Buscado = mString.toStdString();
    cout<<Libro_Buscado;
    controller.reader("test");
}