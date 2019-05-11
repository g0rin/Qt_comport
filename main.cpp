 #include <QApplication>

 #include "mainwindow.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);

     QTextCodec *codec = QTextCodec::codecForName("UTF-8");
     QTextCodec::setCodecForLocale(codec);

     QCoreApplication::setOrganizationName("Golubkin Egor");
     QCoreApplication::setApplicationName("Qt_comport");

     MainWindow mainWin;
     mainWin.show();
     return app.exec();
 }
