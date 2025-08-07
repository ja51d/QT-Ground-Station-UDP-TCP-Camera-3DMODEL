#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QWidget>
#include <QUdpSocket>
#include <QUrl>
#include <QVideoWidget>
#include <QMediaContent>
#include <QMediaRecorder>
#include <QMediaPlayer>
#include <qqml.h>
#include <QTextStream>
#include <QTimer>
#include <QVariant>
#include <QtCore>
#include <QtGui>
#include <QtQuick>
#include <QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
//#include <opencv2/opencv.hpp>
#include <QDateTime>
 #include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;
}
QT_END_NAMESPACE
 struct CanSatdata   // DATA NAMES
{
    short int packetnumber  ;
    float cansatstatus  ;
    unsigned char errorcode ;
    quint64 sendtime;
    float basinc1 ;
    float basinc2  ;
    float height1 ;
    float height2 ;
    float irtifafarki  ;
    float landingspeed  ;
    float temperature ;
    float voltage  ;
    float lat  ;
    float lon  ;
    float alt  ;
    float pitch;
    float roll;
    float yaw;
    int rhrh  ;
    float iots1  ;
    float iot1s2  ;
    int teamno  ;


};

class MainWindow :
                   public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  /*  ScreenRecorder(int fps = 10, const QString &outputFile = "output.avi")
        : fps_(fps), outputFile_(outputFile)
    {
        screen_ = QApplication::primaryScreen();
        frameSize_ = screen_->geometry().size();

        // Initialize OpenCV VideoWriter
        writer_.open(outputFile_.toStdString(),
                     cv::VideoWriter::fourcc('M', 'J', 'P', 'G'),
                     fps_,
                     cv::Size(frameSize_.width(), frameSize_.height()));

        if (!writer_.isOpened()) {
            std::cerr << "Failed to open video writer!" << std::endl;
            exit(1);
        }

        // Timer for capturing frames
        timer_ = new QTimer(this);
        connect(timer_, &QTimer::timeout, this, &ScreenRecorder::captureFrame);
    }
    void start()
    {
        timer_->start(1000 / fps_);
    }

    void stop()
    {
        timer_->stop();
        writer_.release();
    }
  */  CanSatdata datas;

protected:

    void closeEvent(QCloseEvent *event) override;


private slots:
 //void captureFrame();
    void readData();
    void writeData();
    void timerFunc();
    void on_rgb_clicked();
    void rgbData();
    void iotData();
  //  void baslat_transfer();
    void on_ayril_clicked(bool checked);

    void on_pushButton_clicked(bool checked);
    void updateTime();
  //  void iot_transfer();
 /*   void captureFrame()
    {
        QPixmap pixmap = screen_->grabWindow(0);
        QImage img = pixmap.toImage().convertToFormat(QImage::Format_RGB888);
        cv::Mat mat(img.height(), img.width(), CV_8UC3, img.bits(), img.bytesPerLine());
        cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR); // Convert to BGR format
        writer_.write(mat);
    } */



private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QUdpSocket *socket;
    QUdpSocket *socket2;
    QUdpSocket *socket5;
    QUdpSocket *socket6;
    QUdpSocket *socket4;
    QMediaPlayer* sound;
    QString datetimeStr;
    QString year ;
    QString month ;
    QString day ;
    QString hour ;
    QString minute ;
    QString second ;
    QString formattedDateTime;
 //QTimer *timer2;

    QProcess* ffmpegProcess;
    void startScreenRecording();
    void stopScreenRecording();


    //QTimer *captureTimer;
 //cv::VideoWriter writer;
 //bool recordingStarted = false;



  //  QSerialPort *serialPort;
//QList<QSerialPortInfo> mSerialPorts;
 //   float iot_float = 0;
  /*cv::Mat QPixmapToCvMat(const QPixmap& pixmap);
 int fps_;
 QString outputFile_;
 QScreen *screen_;
 QSize frameSize_;
 cv::VideoWriter writer_;
 QTimer *timer_;*/
signals:

    void setCenter(QVariant, QVariant);
    void eulerFunction(QVariant, QVariant, QVariant);
    void setLocMarker(QVariant,QVariant);
};


#endif // MAINWINDOW_H
