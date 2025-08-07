#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFile>
#include <QMediaPlayer>
#include <QQuickItem>
#include <QtCore>
#include <QtGui>
#include <QMediaContent>
#include <QMediaPlayer>
#include <QRandomGenerator>
#include <QUdpSocket>
#include <QVariant>
#include <QWebEngineView>
#include <QDesktopServices>
#include <QUrl>
#include <QWidget>
#include <QVBoxLayout>
#include <QGuiApplication>
#include <QDateTime>
#include <QScreen>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
//#include <opencv2/opencv.hpp>
#include <QWebEngineSettings>
#include <QDir>
#include <QCloseEvent>


template <typename T>
T extractData(const QByteArray& datagram, int& index) {
    T value = qFromBigEndian<T>(reinterpret_cast<const uchar*>(datagram.constData() + index));
    index += sizeof(T);
    return value;
}
void MainWindow::readData()
{
    while (socket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(), datagram.size());

        qDebug() << "Datagram raw data:" << datagram.toHex() << "," << datagram.size();

        if (datagram.size() < 2) {
            qDebug() << "Received datagram is too small!";
            return;
        }

        int index = 0;

        // Extract packet number (2 bytes)
        datas.packetnumber = extractData<short>(datagram, index);
        qDebug() << "Received Packet Number:" << datas.packetnumber;

        // Read additional fields (uncomment as needed)
        // datas.canasstatus = static_cast<unsigned char>(datagram[index++]);
       //  datas.errorcode = static_cast<unsigned char>(datagram[index++]);

       // if (datagram.size() >= index + 8) datas.sendtime = extractData<quint64>(datagram, index);
        if (datagram.size() >= index + 4) datas.basinc1 = extractData<float>(datagram, index);
      //  if (datagram.size() >= index + 4) datas.basinc2 = extractData<float>(datagram, index);
        if (datagram.size() >= index + 4) datas.height1 = extractData<float>(datagram, index);
       // if (datagram.size() >= index + 4) datas.height2 = extractData<float>(datagram, index);
      //  if (datagram.size() >= index + 4) datas.irtifafarki = extractData<float>(datagram, index);
       // if (datagram.size() >= index + 4) datas.landingspeed = extractData<float>(datagram, index);
        if (datagram.size() >= index + 4) datas.temperature = extractData<float>(datagram, index);
        if (datagram.size() >= index + 4) datas.voltage = extractData<float>(datagram, index);
        //if (datagram.size() >= index + 4) datas.lat = extractData<float>(datagram, index);
      //  if (datagram.size() >= index + 4) datas.lon = extractData<float>(datagram, index);
      //  if (datagram.size() >= index + 4) datas.alt = extractData<float>(datagram, index);
        if (datagram.size() >= index + 4) datas.pitch = extractData<float>(datagram, index);
        if (datagram.size() >= index + 4) datas.roll = extractData<float>(datagram, index);
        if (datagram.size() >= index + 4) datas.yaw = extractData<float>(datagram, index);
       // if (datagram.size() >= index + 2) datas.rhrh = extractData<quint16>(datagram, index);
       // if (datagram.size() >= index + 4) datas.iots1 = extractData<float>(datagram, index);
        //if (datagram.size() >= index + 4) datas.iot1s2 = extractData<float>(datagram, index);
        if (datagram.size() >= index + 4) datas.teamno = extractData<int>(datagram, index);

        qDebug() << "Data extraction completed.";
    }
}


void MainWindow::writeData(){

    QByteArray datagram;
    datagram.append('1');
    QHostAddress receiverAddress("172.20.10.9");
    socket2->writeDatagram(datagram, datagram.size(), receiverAddress, 5006);
}

void MainWindow::rgbData()

{
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setByteOrder(QDataStream::BigEndian);
    out << datas.rhrh;
    QHostAddress receiverAddress("192.168.166.192");
    socket4->writeDatagram(datagram, receiverAddress, 0);
}

void MainWindow::iotData()

{
    float iot = 51.51;
    QHostAddress receiverAddress("172.20.10.10");
    QByteArray datagram;
    datagram.resize(sizeof(float));
    qToLittleEndian(iot, reinterpret_cast<uchar *>(datagram.data()));
    socket5->writeDatagram(datagram, receiverAddress, 0);
}

//void MainWindow::baslat_transfer()

//{
 //   QByteArray datagram;
   // datagram.append('1');
   // QHostAddress receiverAddress("172.20.10.1");
   // socket6->writeDatagram(datagram, datagram.size(), receiverAddress, 0);
//}

/*void MainWindow::iot_transfer()
{


    QByteArray iot_data = serialPort->readAll();
    QString str = QString(iot_data);

    static QRegularExpression pattern("iot(.*?)end");
    QRegularExpressionMatchIterator matchIterator = pattern.globalMatch(str);

    while (matchIterator.hasNext()) {

        QRegularExpressionMatch match = matchIterator.next();
        QString dynamicValues = match.captured(1).trimmed();
        QStringList parts = dynamicValues.split(",");

        iot_float=parts[0].toFloat();
        // telemetri.iot=iot_float;

    }

}
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), ffmpegProcess(nullptr)

{

    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL (timeout()),this,SLOT(timerFunc()));

    //timer2 = new QTimer(this);

    // Connect the timer to the updateTime function
    //connect(timer2, &QTimer::timeout, this, &MainWindow::updateTime);

    // Start the timer with a 1000ms (1 second) interval
   // timer2->start(1000);

    // Initial call to display time immediately
   // updateTime();

    ui->progressBar->setStyleSheet(
        "QProgressBar {"
        "    border: 1px solid #D3D3D3;"
        "    border-radius: 8px;"
        "    background-color: #3c5d8e;"
        "    text-align: center;"
        "    font: 12pt 'copperplate';"
        "    color: #D3D3D3;"
        "}"
        "QProgressBar::chunk {"
        "    background-color: QLinearGradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 #4A90E2, stop:1 #a1e8c2);"
        "    border-radius: 8px;"
        "    margin: 1px;"
        "}"
        );




/*
    captureTimer = new QTimer(this);
    connect(captureTimer, &QTimer::timeout, this, &MainWindow::captureFrame);
    captureTimer->start(100); // 10 FPS (100 ms interval)

    // Setup VideoWriter
    int width = ui->quickWidget->width();
    int height = ui->quickWidget->height();
    writer.open("recorded_output.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 10, cv::Size(width, height));

    if (!writer.isOpened()) {
        qWarning("Failed to open video writer.");
    } else {
        recordingStarted = true;
    }
*/





 //connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::iot_transfer);
    QDateEdit *dateEdit = new QDateEdit(this);
    dateEdit->move(600, 20); // x , y
   QFont font2;
    font2.setPointSize(18);         // Set font size
    font2.setFamily("Copperplate");       // Set font style (family)
    font2.setBold(true);            // Set font weight to bold (optional)
    dateEdit->setFont(font2);
    dateEdit->resize(140, 35);
    dateEdit->setDate(QDate::currentDate());
    dateEdit->setDisplayFormat("dd.MM.yyyy");
    dateEdit->setStyleSheet(
        "QDateEdit {"
        "    background-color: #bfe5c4;"
        "    color: black;"
        "    border: 5px solid #305285;"
        "    border-radius: 10px;"
        "    padding: 5px;"
        "}"
        "QDateEdit::drop-down {"
        "    subcontrol-origin: padding;"
        "    subcontrol-position: top right;"      "    width: 20px;"
        "    border-left-width: 1px;"       "    border-left-color: darkgray;"    "   border-left-style: solid;"        "    border-top-right-radius: 3px;"        "    border-bottom-right-radius: 3px;"        "}"       "QDateEdit::down-arrow {"      "    image: url(:/);"
        "}"
        );
    QCPScatterStyle scatterStyle(QCPScatterStyle::ssDisc, Qt::black, 2);

    QFont plotFont = font();
    plotFont.setPointSize(10);






    // Common graph setup function
    auto setupGraph = [&](QCustomPlot* plot, const QString& xLabel, const QString& yLabel,
                          const QPen& pen, const QCPScatterStyle& scatterStyle, int xRangeMin, int xRangeMax, int yRangeMin, int yRangeMax) {
        plot->addGraph();
        plot->graph(0)->setScatterStyle(scatterStyle);
        plot->graph(0)->setLineStyle(QCPGraph::lsLine);
        plot->graph(0)->setPen(pen);
        plot->setBackground(QBrush(Qt::transparent));
        plot->xAxis->setLabel(xLabel);
        plot->yAxis->setLabel(yLabel);
        plot->xAxis->setLabelFont(plotFont);
        plot->xAxis->setTickLabelFont(plotFont);
        plot->yAxis->setLabelFont(plotFont);
        plot->yAxis->setTickLabelFont(plotFont);
        plot->xAxis->setTickLabelColor(Qt::white);
        plot->xAxis->setLabelColor(Qt::white);
        plot->xAxis->setSubTickPen(QPen(Qt::white));
        plot->xAxis->setBasePen(QPen(Qt::white));
        plot->yAxis->setTickLabelColor(Qt::white);
        plot->yAxis->setLabelColor(Qt::white);
        plot->yAxis->setSubTickPen(QPen(Qt::white));
        plot->yAxis->setBasePen(QPen(Qt::white));
        plot->xAxis->setRange(xRangeMin, xRangeMax);
        plot->yAxis->setRange(yRangeMin, yRangeMax);
        };

    QPen pen(QColor(169, 169, 169), 3);

    QPen blackPen(QColor(0, 0, 0), 3);
    setupGraph(ui->bas1, "Paket Numarası", "Basınç1(Pa)", pen, scatterStyle, -55, -5, 1000, 1200);
    setupGraph(ui->bas2, "Paket Numarası", "Basınç2(Pa)", pen, scatterStyle, -55, 5, 1000, 1200);
    setupGraph(ui->height1, "Paket Numarası", "Yükseklik1(m)", pen, scatterStyle, -55, 5, 0, 700);
    setupGraph(ui->height2, "Paket Numarası", "Yükseklik2(m)", pen, scatterStyle, -55, 5, 0, 700);
    setupGraph(ui->temp, "Paket Numarası", "Sıcaklık(C°)", pen, scatterStyle, -55, 5, 0, 40);
    setupGraph(ui->lspeed, "Paket Numarası", "İniş Hızı(m/s)", pen, scatterStyle, -55, 5, 0, 20);
    setupGraph(ui->Irtifa_Farki, "Paket Numarası", "Fark (m)", pen, scatterStyle, -55, 5, 0, 250);
    setupGraph(ui->Voltage, "Paket Numarası", "Gerilim (Volt)", pen, scatterStyle, -55, 5, 0, 10);
    setupGraph(ui->iot, "Paket Numarası", "IoT Sıcaklık1(C°)", blackPen, scatterStyle, 30, 30, 0, 20);
    setupGraph(ui->iot2, "Paket Numarası", "IoT Sıcaklık2(C°)", blackPen, scatterStyle, 50, 30, 0, 20);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(dateEdit);
    setLayout(layout);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/model_cansat.qml")));
    ui->quickWidget->show();
    ui->quickWidget_2->setSource(QUrl(QStringLiteral("qrc:/mapnew.qml")));
    ui->quickWidget_2->show();
    auto objj = ui->quickWidget->rootObject();
    auto obj = ui->quickWidget_2->rootObject();
    connect(this, SIGNAL(setLocMarker(QVariant,QVariant)),obj,SLOT(setLocMarker(QVariant,QVariant)));
    connect(this, SIGNAL(eulerFunction(QVariant,QVariant,QVariant)), objj, SLOT(eulerFunction(QVariant,QVariant,QVariant)));
    emit setCenter(datas.lat,datas.lon);
    emit setLocMarker(datas.lat,datas.lon);
    emit eulerFunction(datas.roll, datas.yaw, datas.pitch);



    QWebEngineView *view = new QWebEngineView(this);
    view->setUrl(QUrl("http://161.9.75.107:5010"));

    view->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessRemoteUrls, true);


    qDebug() << QWebEngineSettings::defaultSettings()->testAttribute(QWebEngineSettings::PluginsEnabled);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::AllowRunningInsecureContent, true);


    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::AllowRunningInsecureContent, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);

    view->setGeometry(1275, 430, 400, 280);
    view->show();










  QPixmap pix(":/itutayf0.png");
    ui->logo->setPixmap(pix);
    QPixmap dur_1("/Users/Javid/desktop/green.png");
    ui->kod2->setPixmap(dur_1.scaled(40,40,Qt::KeepAspectRatio));
    ui->kod3->setPixmap(dur_1.scaled(40,40,Qt::KeepAspectRatio));
    ui->kod4->setPixmap(dur_1.scaled(40,40,Qt::KeepAspectRatio));
    ui->kod5->setPixmap(dur_1.scaled(40,40,Qt::KeepAspectRatio));
    ui->kod6->setPixmap(dur_1.scaled(40,40,Qt::KeepAspectRatio));
     ui->kod1->setPixmap(dur_1.scaled(40,40,Qt::KeepAspectRatio));

    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::Any, 5007);

    socket2 = new QUdpSocket(this);
    socket2->bind(QHostAddress::Any, 5006);

    socket5 = new QUdpSocket(this);
    socket5->bind(QHostAddress::Any, 5001);

    socket6 = new QUdpSocket(this);
    socket6->bind(QHostAddress::Any, 5008);

    socket4 = new QUdpSocket(this);
    socket4->bind(QHostAddress::Any, 5009);

    QFile File("/Users/javid/Desktop/kayit.csv");
    File.open(QIODevice::Append | QIODevice::WriteOnly);

    QTextStream stream(&File);
    stream << "Pak No" << "," << "State" << "," << "Error Code" << "," << "Saat" << "," << "Basinc1"
           << "," << "Basinc2" << ","
           << "Yukseklik1" << "," << "Yukseklik2" << "," << "Fark" << "," << "Hiz" << ","
           << "Sicaklik" << "," << "Gerilim"
           << "," << "Enlem" << "," << "Boylam" << "," << "GPS Yukseklik" << "," << "Pitch" << ","
           << "Roll" << ","
           << "Yaw" << "," << "RHRH" << "," << "Nem" << "," << "Takim No" << "," << "\n";
    File.close();

}

MainWindow::~MainWindow()
{
        stopScreenRecording();
    delete ui;
}


void MainWindow::timerFunc(){

  //  datas.packetnumber +=1;

    readData();
    iotData();
   // datas.basinc1 +=80;
  //  datas.basinc2 += 100;

 //   datas.height1 += 8;

  //  datas.height2 += 7;

  //  datas.voltage +=2 ;

  //  datas.irtifafarki += 0.8;

   // datas.basinc1 += 5;
  //datas.landingspeed += 12;
 //   datas.temperature += 1;


    emit setCenter(datas.lat, datas.lon);
    emit setLocMarker(datas.lat,datas.lon);
    emit eulerFunction(datas.roll, datas.yaw, datas.pitch);

   // datas.roll += 70 ;
   // datas.yaw += 40;
   // datas.pitch += 40;




    QString datetimeStr = QString::number(datas.sendtime);

    QString year = datetimeStr.mid(0, 4);
    QString month = datetimeStr.mid(4, 2);
    QString day = datetimeStr.mid(6, 2);
    QString hour = datetimeStr.mid(8, 2);
    QString minute = datetimeStr.mid(10, 2);
    QString second = datetimeStr.mid(12, 2);


    QString formattedDateTime = day + "/" + month + "/" + year + " " + hour + ":" + minute + ":"
                                + second;

    QString datab = QString::number(datas.packetnumber) + ", " + QString::number(datas.cansatstatus) + ", "
                    + QString::number(datas.errorcode) + ", " + formattedDateTime + ", "
                    + QString::number(datas.basinc1) + ", " + QString::number(datas.basinc2) + ", "
                    + QString::number(datas.height1) + ", " + QString::number(datas.height2) + ", "
                    + QString::number(datas.irtifafarki) + ", " + QString::number(datas.landingspeed) + ", "
                    + QString::number(datas.temperature) + ", " + QString::number(datas.voltage) + ", "
                    + QString::number(datas.lat) + ", " + QString::number(datas.lon) + ", "
                    + QString::number(datas.alt) + ", " + QString::number(datas.pitch) + ","
                    + QString::number(datas.roll) + ", " + QString::number(datas.yaw) + ", "
                    + QString::number(datas.rhrh) + ", " + QString::number(datas.iots1) + ", "+ ","+ QString::number(datas.iot1s2)
                    + QString::number(datas.teamno);

    if (ui->listWidget->count() >= 26) {
        delete ui->listWidget->takeItem(0);
    }

    ui->listWidget->addItem(datab);
    ui->listWidget->scrollToBottom();


   /* QString text = lineEdit->text();
    if (!text.isEmpty()) {
        // Add text to the listWidget
        listWidget->addItem(text);
        // Clear the lineEdit
        lineEdit->clear();
    }
}
*/

    QFile File("/Users/javid/Desktop/kayit.csv");
    File.open(QIODevice::Append |QIODevice::WriteOnly);
    QTextStream stream(&File);
    stream << datab + "\n";
    File.close();






    ui->listWidget->scrollToBottom();
    ui->lcdNumber->display(datas.pitch);
    ui->lcdNumber_2->display(datas.roll);
    ui->lcdNumber_3->display(datas.yaw);
    ui->lcdNumber_4->display(datas.irtifafarki);
    int  x = datas.packetnumber;
    double y1 = datas.basinc1;
    double y2 = datas.basinc2;
    double y3 = datas.height1;
    double y4 = datas.height2;
    double y5 = datas.temperature;
    double y6 = datas.landingspeed;
    double y7 = datas.irtifafarki;
    double y8 = datas.voltage;
    double y9 = datas.temperature;
    double y10 = datas.temperature;

    ui->bas1->addGraph();
    ui->bas1->graph(0)->addData(x, y1);
    ui->bas1->xAxis->setRange(x - 55, x + 5);
    ui->bas1->yAxis->setRange(1000, 1200);
    ui->bas1->replot();
    ui->bas1->update();

    ui->bas2->addGraph();
    ui->bas2->graph(0)->addData(x, y2);
    ui->bas2->xAxis->setRange(x - 55, x + 5);
    ui->bas2->yAxis->setRange(1000, 1200);
    ui->bas2->replot();
    ui->bas2->update();

    ui->height1->addGraph();
    ui->height1->graph(0)->addData(x, y3);
    ui->height1->xAxis->setRange(x - 55, x + 5);
    ui->height1->yAxis->setRange(0, 700);
    ui->height1->replot();
    ui->height1->update();


    ui->height2->addGraph();
    ui->height2->graph(0)->addData(x, y4);
    ui->height2->xAxis->setRange(x - 55, x + 5);
    ui->height2->yAxis->setRange(0, 700);
    ui->height2->replot();
    ui->height2->update();

    ui->temp->addGraph();
    ui->temp->graph(0)->addData(x, y5);
    ui->temp->xAxis->setRange(x - 55, x + 5);
    ui->temp->yAxis->setRange(20, 40);
    ui->temp->replot();
    ui->temp->update();

    ui->lspeed->addGraph();
    ui->lspeed->graph(0)->addData(x, y6);
    ui->lspeed->xAxis->setRange(x - 55, x + 5);
    ui->lspeed->yAxis->setRange(0, 20);
    ui->lspeed->replot();
    ui->lspeed->update();

    ui->Irtifa_Farki->addGraph();
    ui->Irtifa_Farki->graph(0)->addData(x, y7);
    ui->Irtifa_Farki->xAxis->setRange(x - 55, x + 5);
    ui->Irtifa_Farki->yAxis->setRange(0, 250);
    ui->Irtifa_Farki->replot();
    ui->Irtifa_Farki->update();

    ui->Voltage->addGraph();
    ui->Voltage->graph(0)->addData(x, y8);
    ui->Voltage->xAxis->setRange(x - 55, x + 5);
    ui->Voltage->yAxis->setRange(0, 10);
    ui->Voltage->replot();
    ui->Voltage->update();

    ui->iot->addGraph();
    ui->iot->graph(0)->addData(x, y9);
    ui->iot->xAxis->setRange(x - 55, x + 5);
    ui->iot->yAxis->setRange(0, 20);
    ui->iot->replot();
    ui->iot->update();

    ui->iot2->addGraph();
    ui->iot2->graph(0)->addData(x, y10);
    ui->iot2->xAxis->setRange(x - 55, x + 5);
    ui->iot2->yAxis->setRange(0, 20);
    ui->iot2->replot();
    ui->iot2->update();

    QPixmap red("/Users/Javid/desktop/red.png");
    QPixmap green("/Users/Javid/desktop/green.png");

    QMediaPlayer *sound = new QMediaPlayer;
    sound->setMedia(QUrl::fromLocalFile("/Users/Javid/desktop/alarm.mp3"));
    sound->setVolume(10);

    bool errorDetected = false;

    if ((datas.errorcode & 0x01) != 0) {
        ui->kod1->setPixmap(red.scaled(40, 40, Qt::KeepAspectRatio));
        errorDetected = true;
    } else {
        ui->kod1->setPixmap(green.scaled(40, 40, Qt::KeepAspectRatio));
    }

    if ((datas.errorcode & 0x02) != 0) {
        ui->kod2->setPixmap(red.scaled(40, 40, Qt::KeepAspectRatio));
        errorDetected = true;
    } else {
        ui->kod2->setPixmap(green.scaled(40, 40, Qt::KeepAspectRatio));
    }

    if ((datas.errorcode & 0x04) != 0) {
        ui->kod3->setPixmap(red.scaled(40, 40, Qt::KeepAspectRatio));
        errorDetected = true;


    } else {
        ui->kod3->setPixmap(green.scaled(40, 40, Qt::KeepAspectRatio));
    }

    if ((datas.errorcode & 0x08) != 0) {
        ui->kod4->setPixmap(red.scaled(40, 40, Qt::KeepAspectRatio));
        errorDetected = true;
    } else {
        ui->kod4->setPixmap(green.scaled(40, 40, Qt::KeepAspectRatio));
    }

    if ((datas.errorcode & 0x10) != 0) {
        ui->kod5->setPixmap(red.scaled(40, 40, Qt::KeepAspectRatio));
        errorDetected = true;
    } else {
        ui->kod5->setPixmap(green.scaled(40, 40, Qt::KeepAspectRatio));
    }

    if ((datas.errorcode & 0x20) != 0) {
        ui->kod6->setPixmap(red.scaled(40, 40, Qt::KeepAspectRatio));
        errorDetected = true;
    } else {
        ui->kod6->setPixmap(green.scaled(40, 40, Qt::KeepAspectRatio));
    }

    if (errorDetected) {
        sound->play();
    }
}

void MainWindow::on_pushButton_clicked(bool checked)
{

    if(checked==true){
        ui->pushButton->setText("");
        timer->start(1000);
    }
    else{
        ui->pushButton->setText("");
        timer->stop();

    }
}
/*void MainWindow::captureFrame() {
    if (!recordingStarted) return;

    QPixmap pixmap = ui->quickWidget->grab();  // grab the frame
    QImage image = pixmap.toImage().convertToFormat(QImage::Format_RGB888);

    cv::Mat mat(image.height(), image.width(), CV_8UC3, (void*)image.bits(), image.bytesPerLine());
    cv::Mat matBGR;
    cv::cvtColor(mat, matBGR, cv::COLOR_RGB2BGR);  // OpenCV uses BGR

    writer.write(matBGR);
}
*/
void MainWindow::on_rgb_clicked()
{
    datas.rhrh = 0;

    QString rhrh_string = ui->lineEdit->text();

    if (rhrh_string.at(1) == 'G') {
        datas.rhrh = datas.rhrh | 0x01;
    }

    if (rhrh_string.at(1) == 'B') {
        datas.rhrh = datas.rhrh | 0x02;
    }

    if (rhrh_string.at(1) == 'R') {
        datas.rhrh = datas.rhrh | 0x04;
    }
    if (rhrh_string.at(3) == 'G') {
        datas.rhrh = datas.rhrh | (0x01 << 8);
    }
    if (rhrh_string.at(3) == 'B') {
        datas.rhrh = datas.rhrh | (0x02 << 8);
    }
    if (rhrh_string.at(3) == 'R') {
        datas.rhrh = datas.rhrh | (0x04 << 8);
    }

    QChar sec_f = rhrh_string.at(0);
    QChar sec_s = rhrh_string.at(2);

    datas.rhrh = datas.rhrh | (sec_f.digitValue() << 3) | (sec_s.digitValue() << 11);

    rgbData();
}
void MainWindow::on_ayril_clicked(bool checked)

{
    writeData();
}

void MainWindow::updateTime()
{
    // Get the current time
    QTime currentTime = QTime::currentTime();

    // Format the time string (HH:mm:ss)
    QString timeText = currentTime.toString("HH:mm:ss");

    // Update the QLabel with the current time
    ui->label_12->setText(timeText);
}

void MainWindow::startScreenRecording()
{
    ffmpegProcess = new QProcess(this);

    // Make sure ffmpeg is installed here: /opt/homebrew/bin/ffmpeg
    // Adjust path if needed (e.g. /usr/local/bin/ffmpeg or just "ffmpeg" if in PATH)
    QString ffmpegPath = "ffmpeg";


    QStringList arguments = {
        "-y",
        "-f", "avfoundation",
        "-framerate", "30",
        "-i", "1:none",
        "-vf", "crop=800:500:2550:880",
        QDir::homePath() + "/Desktop/javid.mp4"
    };

    ffmpegProcess->start(ffmpegPath, arguments);

    if (!ffmpegProcess->waitForStarted()) {
        qDebug() << "FFmpeg failed to start!";
    } else {
        qDebug() << "Recording started.";
    }
}


void MainWindow::stopScreenRecording()
{
    if (ffmpegProcess && ffmpegProcess->state() == QProcess::Running) {
        ffmpegProcess->terminate();  // try to stop gracefully
        if (!ffmpegProcess->waitForFinished(3000)) {
            ffmpegProcess->kill();  // force kill if needed
        }
        qDebug() << "Recording stopped.";
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    stopScreenRecording();
    QMainWindow::closeEvent(event);
}
