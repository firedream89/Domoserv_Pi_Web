#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <QStringList>
#include <QtWebSockets/QtWebSockets>
#include <QPushButton>
#include <QTime>
#include <QLineEdit>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QValueAxis>
#include <QBarCategoryAxis>

#include </usr/local/qwt-6.1.4/src/qwt_series_store.h>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Interface;
}

enum order {
    confort,
    eco,
    horsgel
};

enum mode {
    automatic,
    semiAuto,
    manual
};

enum temp {
    Interieur,
    Exterieur
};

class Interface : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = nullptr);
    ~Interface();
    bool ConnectToServer();
    void SendMessage(QString text);
    void Disconnect();

private slots:
    void Auth();
    void ReceiptMessage(QString text);
    void ChangeStateSocket();
    void UpdateData();
    void UpdateInterface(QString data);
    QString OrderConvertToString(int order);
    int OrderConvertToInt(QString order);
    QString ModeConvertToString(int mode);
    int ModeConvertToInt(QString mode);
    QString ConvertToTime(int time);
    void ChangeStateInterface();
    void ChangeStateZ();
    void ChangeModeZ();
    void UpdateTable();

private:
    Ui::Interface *ui;
    QString Encrypt(QString text);
    QString Decrypt(QString text);
    int PKEY[50];
    QWebSocket socket;
    QTimer _update;
    QStringList _temp;
    QStringList _order;
    QStringList _cpt;
};

#endif // INTERFACE_H
