#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);

private slots:
	void startTimer();
	void stopTimer();
	void pauseTimer();
private:
	QLabel* timeLabel;
	QPushButton* startButton;
	QPushButton* stopButton;
	QPushButton* pauseButton;
	QTimer* timer;
	int timeCount;

	void updateTimerLabel();
};
#endif
