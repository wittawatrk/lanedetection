#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowState(Qt::WindowMaximized);
    // open video
    video.open("D:\\download\\test.avi");
        //check
        if(!video.isOpened()==true){

         return;}
//set timer
         vtimer = new QTimer(this);
         connect(vtimer,SIGNAL(timeout()),this,SLOT(processFrameAndUpdateGUI()));
          vtimer->start(20);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::processFrameAndUpdateGUI(){

     video.read(picori);

  if(picori.empty() == true)
   {
        return;}

  cv::Canny(picori, greypic, 300,300, 3);
  cv::HoughLines(greypic,line,1,CV_PI/180,85);

  for (size_t i = 0; i < line.size(); i++)
          {
              float rho = line[i][0], theta = line[i][1];
              cv::Point pt1, pt2;
              double a = cos(theta), b = sin(theta);
              double x0 = a*rho, y0 = b*rho;
              pt1.x = cvRound(x0 + 1000 * (-b));
              pt1.y = cvRound(y0 + 1000 * (a));
              pt2.x = cvRound(x0 - 1000 * (-b));
              pt2.y = cvRound(y0 - 1000 * (a));
              cv::line(picori, pt1, pt2, cv::Scalar(0, 255, 255), 3, CV_AA);
          }
    QImage ori((uchar*) picori.data,picori.cols,picori.rows,picori.step,QImage::Format_RGB888);
    ui->VDOlabel->setPixmap(QPixmap::fromImage(ori));
    ui->VDOlabel->setMaximumSize(640,480);
}
