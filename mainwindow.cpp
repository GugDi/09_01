#include "mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget* parent)	: QMainWindow(parent), timeCount(0){}

void MainWindow::startTimer(){}
void MainWindow::stopTimer(){
	timer->stop();
	timeCount = 0;
	updateTimerLabel();
}
void MainWindow::pauseTimer(){
	timer->stop();
}
void MainWindow::updateTimerLabel(){
	timeLabel->setText(QString::number(timeCount));
}
