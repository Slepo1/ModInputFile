#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include "MyTimer.h"

MyTimer::MyTimer()
{
	// Создаем таймер
	timer = new QTimer(this);

	// Подключаем сигнал таймера к слоту
	connect(timer, &QTimer::timeout, this, &MyTimer::timerEvent);

	// Устанавливаем интервал таймера в миллисекундах
	timer->start(5000); // Запускаем таймер с интервалом 5 секунд
}

void MyTimer::timerEvent()
{
	qDebug() << "Таймер сработал!";
}

