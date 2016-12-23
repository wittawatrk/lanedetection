#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <Qtimer.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
    //openCVClass
    cv::VideoCapture video ;
    cv::Mat picori;
    cv::Mat greypic;
    std::vector<cv::Vec2f> line;

    //timer
    QTimer *vtimer;
    //image
    QImage ori;

  public slots:
  void processFrameAndUpdateGUI();

};

#endif // MAINWINDOW_H
