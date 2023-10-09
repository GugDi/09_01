#include "mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget* parent)	: QMainWindow(parent), timeCount(0){
	setFixedSize(200, 100);
	setWindowTitle("Timer");
	
	timeLabel = new QLabel("0", this);
	timeLabel->setAlignment(Qt::AlignCenter);

	startButton = new QPushButton("Start", this);
	stopButton = new QPushButton("Stop", this);
	pauseButton = new QPushButton("Pause", this);

	QHBoxLayout* layout = new QHBoxLayout;
	layout->addWidget(startButton);
	layout->addWidget(stopButton);
	layout->addWidget(pauseButton);

	QVBoxLayout* mainLayout = new QVBoxLayout;
	mainLayout->addWidget(timeLabel);
	mainLayout->addLayout(layout);

	QWidget* centralWidget = new QWidget(this);
	centralWidget->setLayout(mainLayout);
	setCentralWidget(centralWidget);

	connect(startButton, &QPushButton::clicked, this, &MainWindow::startTimer);
	connect(stopButton, &QPushButton::clicked, this, &MainWindow::stopTimer);
	connect(pauseButton, &QPushButton::clicked, this, &MainWindow::pauseTimer);

	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, [this]() {
		++timeCount;
		updateTimerLabel();
		});
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
