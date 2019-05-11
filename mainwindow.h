#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>

#include "ui_main_window_form.h"
#include "crc_form.h"
#include "command_form.h"

enum TypeDataInOut {DEC_, ASCII_, NMEA_, HEX_, BIN_};

class MainWindow : public QMainWindow, private Ui::MainWindow {
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event);

private:
    QDialogCRC *dlgCRC;
    QDialogCommand *dlgCommand;

    QHash<QString, QString> m_hashCommand;

    QSerialPort *port;
    QTimer *timerout;
    QMenu *fileMenu;
    QMenu *helpMenu;
    QMenu *editMenu;
    QAction *exitAct;
    QAction *aboutAct;
    QAction *calcTimeoutAct;
    QAction *calcCRCAct;
    QAction *comandFormAct;
    QTime *timeoutTime;
    QLabel *labelReceive;
    QLabel *labelTransmit;
    int counter_in,counter_out;
    bool bRTS;
    bool bDTR;
    void createMainMenu();
    void createDialogs();
    void getdataout(QByteArray *data);
    QString transformInpData(const QByteArray *data);

    void readSettings();
    void writeSettings();

private slots:
    void about();
    void applyPortOptions();
    void btsendClick();
    void btstopsendClick();
    void closePort();
    void enabledPortBt();
    void openPort();
    void receiveMsg(const QTime timesl, const QByteArray *data);
    void SetCurComboBState();
    void setTimeoutTimer(bool state);
    void transmitMsg();
    void intervalChange(int value);
    void calcCRC();
    void setTextCopy (QString & str);
    void open();
    void save();
    void readFromPort();
    void changeCommand();
    void commandChanged (const QHash<QString, QString> &data);
};

#endif
