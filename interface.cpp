#include "interface.h"
#include "ui_interface.h"

//ip websocket : ws://ip:port
QString ip = "ws://192.168.1.73:52000";

Interface::Interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);

    for(int i=0;i<50;i++) {
        PKEY[i] = 0;
    }

    _update.setInterval(60000);
    _update.setSingleShot(false);

    connect(ui->btConnection,&QPushButton::clicked,this,&Interface::ChangeStateSocket);
    connect(ui->Set,&QPushButton::clicked,this,&Interface::ChangeStateInterface);
    connect(ui->bStateZ1,&QPushButton::clicked,this,&Interface::ChangeStateZ);
    connect(ui->bStateZ2,&QPushButton::clicked,this,&Interface::ChangeStateZ);
    connect(ui->bModeZ1,&QPushButton::clicked,this,&Interface::ChangeModeZ);
    connect(ui->bModeZ2,&QPushButton::clicked,this,&Interface::ChangeModeZ);

    connect(&socket,&QWebSocket::connected,this,&Interface::Auth);
    connect(&socket,&QWebSocket::textMessageReceived,this,&Interface::ReceiptMessage);
    connect(&socket,&QWebSocket::disconnected,this,&Interface::Disconnect);
    connect(ui->Connect,&QPushButton::clicked,this,&Interface::ChangeStateSocket);

    connect(&_update,&QTimer::timeout,this,&Interface::UpdateData);

    ChangeStateSocket();
    ChangeStateInterface();

    _cpt.append("Test");
    _order.append("Test");
}

Interface::~Interface()
{
    delete ui;
}

void Interface::ChangeStateSocket()
{
    if(ui->status->text() == "Connected") {
        qDebug() << "Disconnect";
        if(socket.state() == QAbstractSocket::ConnectedState)
            Disconnect();
        qDebug() << "Disconnect2";
        ui->btConnection->setText("Connect");
        ui->status->setText("Disconnected");
        ui->main->hide();
        ui->Login->show();

        _update.stop();
    }
    else {
        qDebug() << "Connect";
        ConnectToServer();
        qDebug() << "Connect2";
        ui->main->show();
        ui->Login->hide();
        ui->btConnection->setText("Disconnect");
        ui->status->setText("Connected");

        _update.start();
    }
}

void Interface::ChangeStateZ()
{
    //Get State
    QString state;
    int zone = 1;
    if(qobject_cast<QPushButton *>(sender()) == ui->bStateZ1) {
        ui->bStateZ1->setEnabled(false);
        state = ui->bStateZ1->text();
    }
    else {
        ui->bStateZ2->setEnabled(false);
        state = ui->bStateZ2->text();
        zone = 2;
    }

    //QString > Int
    int iState = confort;
    if(state == "Confort") {
        iState = eco;
    }

    SendMessage("CVOrder|SetZ" + QString::number(zone) + "Order=" + QString::number(iState));
}

void Interface::ChangeModeZ()
{
    QString mode;
    int zone = 1;
    if(qobject_cast<QPushButton *>(sender()) == ui->bModeZ1) {
        ui->bModeZ1->setEnabled(false);
        mode = ui->bModeZ1->text();
    }
    else {
        ui->bModeZ2->setEnabled(false);
        mode = ui->bModeZ2->text();
        zone = 2;
    }

    int iMode = automatic;
    if(mode == "Automatique") {
        iMode = manual;
    }

    SendMessage("CVOrder|SetZ" + QString::number(zone) + "Status=" + QString::number(iMode));
}

void Interface::ChangeStateInterface()
{
    if(!ui->bStateZ1->isHidden()) {
        ui->bStateZ1->hide();
        ui->stateZ1->show();

        ui->bStateZ2->hide();
        ui->stateZ2->show();

        ui->bModeZ1->hide();
        ui->modeZ1->show();

        ui->bModeZ2->hide();
        ui->modeZ2->show();
    }
    else {
        ui->stateZ1->hide();
        ui->bStateZ1->show();

        ui->stateZ2->hide();
        ui->bStateZ2->show();

        ui->modeZ1->hide();
        ui->bModeZ1->show();

        ui->modeZ2->hide();
        ui->bModeZ2->show();
    }
}

void Interface::UpdateTable()
{
    QStringList categories;
        QLineSeries *series = new QLineSeries();
        series->setName("Intérieur");
        int pos = 0;
        for(int i=0;i<_temp.count();i++) {
            if(_temp.at(i).split("|").at(2).toInt() == Interieur) {
                series->append(pos,_temp.at(i).split("|").at(3).toDouble());
                categories.append(_temp.at(i).split("|").at(1));
                pos++;
            }
        }

        QLineSeries *series2 = new QLineSeries();
        series2->setName("Extérieur");
        pos = 0;
        for(int i=0;i<_temp.count();i++) {
            if(_temp.at(i).split("|").at(2).toInt() == Exterieur) {
                series2->append(pos,_temp.at(i).split("|").at(3).toDouble());
                pos++;
            }
        }
        QChart *chart = new QChart();

        chart->addSeries(series);
        chart->addSeries(series2);


        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);
        series2->attachAxis(axisX);
        axisX->setRange(categories.first(), categories.last());

        QValueAxis *axisY = new QValueAxis();
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);
        series2->attachAxis(axisY);
        axisY->setRange(0, 50);

        chart->setTitle("Température");
    //![3]

    //![4]

    //![4]


    //![5]

        if(!ui->main->findChild<QChartView*>("Temp")) {
            QChartView *chartView = new QChartView(chart);
            chartView->setObjectName("Temp");
            chartView->setRenderHint(QPainter::Antialiasing);
            ui->Chart->addWidget(chartView);
        }
        else {
            ui->main->findChild<QChartView*>("Temp")->setChart(chart);
        }
    //![5]

    /*
    while(ui->table->rowCount() > 0) {
        ui->table->removeRow(0);
    }
    while(ui->table->columnCount() > 0) {
        ui->table->removeColumn(0);
    }

    if(!_temp.isEmpty() && !_order.isEmpty() && !_cpt.isEmpty()) {
        //Table
        for(int i=0;i<_temp.count();i++) {
            if(!_temp.at(i+1).isNull() && _temp.at(i+1).split("|").at(0) == _temp.at(i).split("|").at(0) &&
                    _temp.at(i+1).split("|").at(1) == _temp.at(i).split("|").at(1) &&
                    _temp.at(i+1).split("|").at(2) != _temp.at(i).split("|").at(2)) {
                ui->table->insertColumn(0);
                ui->table->setColumnWidth(0,10);
                ui->table->insertColumn(0);
                ui->table->setColumnWidth(0,10);
                ui->table->insertColumn(0);
                ui->table->setColumnWidth(0,10);


                //row
                //i
                double result =  _temp.at(i).split("|").last().toDouble();
                int r = static_cast<int>(result) / 2 - ui->table->rowCount();
                for(int i2=0;i2<=r;i2++) {
                    ui->table->insertRow(0);
                }
                //i+1
                result =  _temp.at(i+1).split("|").last().toDouble();
                r = static_cast<int>(result) / 2 - ui->table->rowCount();
                for(int i2=0;i2<=r;i2++) {
                    ui->table->insertRow(0);
                }

                //color
                //i
                result =  _temp.at(i).split("|").last().toDouble();
                r = static_cast<int>(result)/2+1;
                for(int i2=ui->table->rowCount()-1;i2>ui->table->rowCount()-r;i2--) {
                    ui->table->setItem(i2,0,new QTableWidgetItem());
                    ui->table->item(i2,0)->setBackgroundColor(QColor(255,0,0));
                }
                //i+1
                result =  _temp.at(i+1).split("|").last().toDouble();
                r = static_cast<int>(result)/2+1;
                for(int i2=ui->table->rowCount()-1;i2>ui->table->rowCount()-r;i2--) {
                    ui->table->setItem(i2,1,new QTableWidgetItem());
                    ui->table->item(i2,1)->setBackgroundColor(QColor(0,255,0));
                }

                //info
                //i
                result =  _temp.at(i).split("|").last().toDouble()/2+1;
                r = ui->table->rowCount() - static_cast<int>(result);
                if(r >= 0) {
                    ui->table->setItem(r,0,new QTableWidgetItem(_temp.at(i).split("|").last()));
                }
                //i+1
                result =  _temp.at(i+1).split("|").last().toDouble()/2+1;
                r = ui->table->rowCount() - static_cast<int>(result);
                if(r >= 0) {
                    ui->table->setItem(r,1,new QTableWidgetItem(_temp.at(i+1).split("|").last()));
                }
                i++;
            }
            else {
                ui->table->insertColumn(0);
                ui->table->insertColumn(0);

                //row
                //i
                double result =  _temp.at(i).split("|").last().toDouble();
                int r = static_cast<int>(result) / 2 - ui->table->rowCount();
                for(int i2=0;i2<=r;i2++) {
                    ui->table->insertRow(0);
                }

                //color
                //i
                result =  _temp.at(i).split("|").last().toDouble();
                r = static_cast<int>(result)/2+1;
                for(int i2=ui->table->rowCount()-1;i2>ui->table->rowCount()-r;i2--) {
                    ui->table->setItem(i2,0,new QTableWidgetItem());
                    ui->table->item(i2,0)->setBackgroundColor(QColor(255,0,0));
                }

                //info
                //i
                r = ui->table->rowCount()/2-r+1;
                if(r >= 0) {
                    ui->table->setItem(r,0,new QTableWidgetItem(_temp.at(i).split("|").last()));
                }
            }
        }

        //Items
        int numb = 2;
        for(int i=ui->table->rowCount()-1;i>=0;i--) {
            ui->table->setVerticalHeaderItem(i,new QTableWidgetItem(QString::number(numb)));
            numb += 2;
        }

        ui->table->insertRow(ui->table->rowCount());


        ui->table->resizeRowsToContents();
    }
*/
}

QString Interface::OrderConvertToString(int order)
{
    switch (order) {
    case confort:
        return "Confort";
    case eco:
        return "Eco";
    case horsgel:
        return "Hors Gel";
    default:
        return "Erreur";
    }
}

int Interface::OrderConvertToInt(QString order)
{
    if(order == "Confort") {
        return confort;
    }
    else if(order == "Eco") {
        return eco;
    }
    else if(order == "Hors Gel") {
        return horsgel;
    }
    else {
        return -1;
    }
}

QString Interface::ModeConvertToString(int mode)
{
    switch (mode) {
    case automatic:
        return "Automatique";
    case manual:
        return "Manuel";
    default:
        return "Erreur";
    }
}

int Interface::ModeConvertToInt(QString mode)
{
    if(mode == "Automatique") {
        return automatic;
    }
    else if(mode == "Manuel") {
        return manual;
    }
    else {
        return -1;
    }
}

QString Interface::ConvertToTime(int time)
{
    QTime t;
    t.setHMS(0,0,0);
    t = t.addSecs(time);
    return t.toString("hh:mm");
}

void Interface::UpdateData()
{
    SendMessage("CVOrder|GetZ1Order");
    SendMessage("CVOrder|GetZ2Order");
    SendMessage("CVOrder|GetZ1Status");
    SendMessage("CVOrder|GetZ2Status");
    SendMessage("CVOrder|GetRemainingTimeZ1");
    SendMessage("CVOrder|GetRemainingTimeZ2");
    SendMessage("CVOrder|GetTemp;0");
    SendMessage("CVOrder|GetTemp;1");
    SendMessage("CVOrder|GetDataTemp;2019-08-26:2019-08-26");
}

void Interface::UpdateInterface(QString data)
{
    if(data.contains('='))
    {
        if(data.contains("GetZ1Order")) {
            ui->stateZ1->setText(OrderConvertToString(data.split("=").last().toInt()));
            ui->bStateZ1->setText(ui->stateZ1->text());
            ui->bStateZ1->setEnabled(true);
        }
        else if(data.contains("GetZ2Order")) {
            ui->stateZ2->setText(OrderConvertToString(data.split("=").last().toInt()));
            ui->bStateZ2->setText(ui->stateZ2->text());
            ui->bStateZ2->setEnabled(true);
        }
        else if(data.contains("GetZ1Status")) {
            ui->modeZ1->setText(ModeConvertToString(data.split("=").last().toInt()));
            ui->bModeZ1->setText(ui->modeZ1->text());
            ui->bModeZ1->setEnabled(true);
            SendMessage("CVOrder|GetRemainingTimeZ1");
        }
        else if(data.contains("GetZ2Status")) {
            ui->modeZ2->setText(ModeConvertToString(data.split("=").last().toInt()));
            ui->bModeZ2->setText(ui->modeZ2->text());
            ui->bModeZ2->setEnabled(true);
            SendMessage("CVOrder|GetRemainingTimeZ2");
        }
        else if(data.contains("GetRemainingTimeZ1")) {
            ui->tmpRestZ1->setText(ConvertToTime(data.split("=").last().toInt()));
        }
        else if(data.contains("GetRemainingTimeZ2")) {
            ui->tmpRestZ2->setText(ConvertToTime(data.split("=").last().toInt()));
        }/*
        else if(data.contains("GetDataCPTEnergy")) {

            if(result.length == 2) {
                console.log("Energy : " + result[1]);
                document.getElementById("inData").innerHTML = result[1];
            }
        }
        else if(data.contains("GetDataOrder")) {

            if(result.length == 2) {
                console.log("State : " + result[1]);
                document.getElementById("inData").innerHTML = result[1];
            }
        }*/
        else if(data.contains("GetDataTemp")) {
            qDebug() << data;
            _temp = data.split("=").last().split(",");
            UpdateTable();
        }
        else if(data.contains("GetTemp;0")) {
            ui->tempInt->setText(data.split("=").last() + "°C");
        }
        else if(data.contains("GetTemp;1")) {
            ui->tempExt->setText(data.split("=").last() + "°C");
        }
    }
}

bool Interface::ConnectToServer()
{
    if(socket.state() == QAbstractSocket::ConnectedState) {
        return true;
    }
    socket.open(QUrl(ip));

    if(socket.state() == QAbstractSocket::ConnectedState) {
        return true;
    }
    return false;
}

void Interface::Disconnect()
{
    socket.close();
    for(int i=0;i<50;i++) {
        PKEY[i] = 0;
    }

    //clear interface
    ui->stateZ1->clear();
    ui->stateZ2->clear();
    ui->modeZ1->clear();
    ui->modeZ2->clear();
    ui->tmpRestZ1->clear();
    ui->tmpRestZ2->clear();
    ui->tempExt->clear();
    ui->tempInt->clear();
    ui->bModeZ1->setText("");
    ui->bModeZ2->setText("");
    ui->bStateZ1->setText("");
    ui->bStateZ2->setText("");
}

void Interface::Auth()
{
    if(PKEY[0] == 0 && PKEY[1] == 0) {
        socket.sendTextMessage(ui->passwd->text());
    }
}

void Interface::SendMessage(QString text)
{
    socket.sendTextMessage(Encrypt(text));
}

void Interface::ReceiptMessage(QString text)
{
    if(PKEY[0] == 0 && PKEY[1] == 0) {
        QStringList list = text.split(" ");
        if(list.count() == 50) {
            for(int i=0;i<list.count();i++) {
                PKEY[i] = list.at(i).toInt();
            }
            UpdateData();
        }
    }
    else {
        UpdateInterface(Decrypt(text));
    }
}

QString Interface::Encrypt(QString text)
{
    QString crypt;
    int idk(0);
    for(int i = 0;i<text.count();i++)
    {
        if(idk == 50)
        {
            idk = 0;
        }
        int t = text.at(i).unicode();
        t -= PKEY[idk];
        if(t > 250)
        {
            t = t - 250;
        }
        else if(t < 0)
        {
            t = t + 250;
        }
        if(t == 34)//si '
        {
            t = 251;
        }
        else if(t == 39)//ou "
        {
            t = 252;
        }
        crypt += QChar(t).toLatin1();
        idk++;
    }
    return crypt;
}

QString Interface::Decrypt(QString text)
{
    QString decrypt;
    int idk(0);
    for(int i = 0;i<text.count();i++)
    {
        if(idk == 50)
        {
            idk = 0;
        }
        int t = text.at(i).unicode();
        if(t == 251)//retour a '
        {
            t = 34;
        }
        else if(t == 252)//retour a "
        {
            t = 39;
        }
        t += PKEY[idk];
        if(t < 0)
        {
            t = t + 250;
        }
        else if(t > 250)
        {
            t = t - 250;
        }
        decrypt += QChar(t).toLatin1();
        idk++;
    }
    return decrypt;
}
