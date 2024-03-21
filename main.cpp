#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include "ModFile.h"
#include "MyTimer.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	MyTimer timer;

	QTextStream input(stdin); // Для чтения пути директории и маски входных файлов

	qDebug() << "Введите путь к директории с входными файлами: ";
	QString dirPath = input.readLine(); // /home/bad/Рабочий стол/C++Project/QtProject/QtModFIle/ModFile/inputFiles

	qDebug() << "Введите маску входных файлов(Пример: *.txt): ";
	QString fMask = input.readLine().trimmed();

	ModFile test(dirPath, fMask); // Конструктор

	test.fMaska(); //Метод для отображения файлов с учетом маски входных файлов

	qDebug() << "Введите путь к директории с результирующими файлами: ";
	QString newDir = input.readLine().trimmed(); //Здесь будет храниться директория для выходных файлов
	test.setNewd(newDir); // /home/bad/Рабочий стол/C++Project/QtProject/QtModFIle/ModFile/outputFiles

	qDebug() << "Введите название входного файла: ";
	QString fileName = input.readLine().trimmed();

	// Проверяем, открыт ли файл для записи
	QFile inputFile(fileName);
	if (inputFile.isOpen())
	{
		qDebug() << "Файл" << fileName << "открыт, выход из программы";
		app.quit();
	}
	else // файл не открыт для записи
	{
		qDebug() << "Введите значение 8 байт для бинарной операции модификации файла типа long long int(Пример '1122334455667788'): ";
		QString xorV = input.readLine().trimmed();
		long long int xorValue = xorV.toLongLong(); // xor значение
		test.xorFile(fileName, xorValue);
	}


	qDebug() << "Введите название входного файла, который собираетесь удалить, либо введите что-нибудь другое чтобы пропустить этот шаг: ";
	fileName = input.readLine().trimmed();
	test.deleteFile(fileName); // Метод для удаления файла

	return app.exec();
}
