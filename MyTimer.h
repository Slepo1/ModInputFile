#ifndef MYTIMER_H
#define MYTIMER_H
#include <QCoreApplication>
#include <QTimer>

class MyTimer : public QObject {
	Q_OBJECT

public:
	MyTimer();

public slots:
	// Слот, который будет вызываться по истечении таймера
	void timerEvent();

private:
	QTimer *timer;
};

#endif // MYTIMER_H
