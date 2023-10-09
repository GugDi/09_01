#include "mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget* parent)	: QMainWindow(parent), timeCount(0){
	setFixedSize(200, 100);
	setWindowTitle("Timer");
}

void MainWindow::startTimer(){
	timer->start(1000); // Start the timer with 1 second interval
}

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
