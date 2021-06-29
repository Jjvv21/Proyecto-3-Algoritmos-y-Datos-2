#include <QApplication>
#include <QPushButton>
#include "Window.h"

int main(int argc, char *argv[]) {
    //Controller controller = Controller("/home/diabloget/CLionProjects/TECFS/cmake-build-debug/test.txt");
    //Controller controller = Controller();
    //controller.addBook("/home/diabloget/CLionProjects/TECFS/cmake-build-debug/test.txt");
    //controller.reader("test");

    QApplication app (argc, argv);
    QWidget *window = new Window;
    window->show();
    return app.exec();
}
