
#ifndef WINDOW_H
#define WINDOW_H

#include <QKeyEvent>
#include <QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtCore/QCoreApplication>
#include <QtGui/QTextBlock>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QListView>
#include <QPixmap>
#include <QGridLayout>
#include "Controller.h"


using namespace std;
/**
 * @brief The Window class : Clase que corresponde a la ventana principal
 */
class Window : public QWidget {
Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);
    Controller controller;

//QString getEditorReading();
private slots:
    void BuscarLibro();
    void AbrirTxT();
    void CargarXML();

private:
    QGridLayout *layout;
    QHBoxLayout *box1;
    QHBoxLayout *box2;
    QPushButton *XML;
    QPushButton *TXT;
    QLineEdit   *Buscador;
    QPushButton *Buscar;
    QTextEdit *Lector;
};
#endif // WINDOW_H

// void RefreshRAMBox();