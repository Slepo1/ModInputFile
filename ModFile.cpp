#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include "ModFile.h"

ModFile::ModFile(QString dirPath, QString fMask)
{
	this->directoryPath = dirPath;
	this->fileMask = fMask;
}

void ModFile::fMaska()
{
	QDir directory(directoryPath);
	QStringList fileList = directory.entryList(QStringList(fileMask), QDir::Files);

	qDebug() << "Входные файлы подходящие маске" << fileMask << "В директории" << directoryPath << ":";

	foreach (QString file, fileList)
	{
		qDebug() << file;
	}
}

void ModFile::deleteFile(QString fileName)
{
	QFile file(directoryPath + "/" + fileName);

	if(file.remove())
	{
		qDebug() << "Файл удален";
	}
	else
	{
		qDebug() << "Ошибка при удалении файла";
	}
}

void ModFile::setNewd(QString newDir)
{
	this->newDirectory = newDir;
}

void ModFile::xorFile(QString fileName, long long int xorValue)
{
	// Открываем исходный файл для чтения
	QFile sourceFile(directoryPath + "/" + fileName);
	if (!sourceFile.open(QIODevice::ReadOnly))
	{
		qDebug() << "Ошибка при открытии файла для чтения:" << sourceFile.errorString();
		return;
	}

	// Считываем содержимое файла в буфер
	QByteArray buffer = sourceFile.readAll();

	// Применяем операцию XOR к каждому байту в буфере
	for (int i = 0; i < buffer.size(); ++i)
	{
		buffer[i] = buffer[i] ^ xorValue;
	}

	// Проверяем, существует ли файл с таким именем в директории назначения
	QFile destinationFile(newDirectory + "/result" + fileName);
	if (destinationFile.exists())
	{
		// Если файл уже существует, предоставляем пользователю выбор
		qDebug() << "Файл с именем /result"" << fileName << уже существует в указанной директории";
		qDebug() << "Хотите перезаписать его (введите 1) или добавить счетчик к имени файла (введите 2)?";
		QTextStream inputStream(stdin);
		int choice = inputStream.readLine().toInt();
		if (choice != 1)
		{
			// Если пользователь ввел не 1, добавляем счетчик к имени файла
			int counter = 1;
			while (destinationFile.exists())
			{
				destinationFile.setFileName(newDirectory + "/result" + QString("%1_%2").arg(QFileInfo(directoryPath + "/" + fileName).baseName()).arg(counter++) + "." + QFileInfo(directoryPath + "/" + fileName).suffix());
			}
		}
	}


	//QFile destinationFile(newDirectory + "/result" + fileName);
	if(!destinationFile.open(QIODevice::WriteOnly))
	{
		qDebug() << "Ошибка при создании файла записи" << destinationFile.errorString();
		return;
	}

	qint64 byresWritten = destinationFile.write(buffer);
	if(byresWritten != buffer.size())
	{
		qDebug() << "Ошибка записи данных в файл" << destinationFile.errorString();
		return;
	}

	qDebug() << "Файл успешно записан и сохранен в новой директорией с припиской result";

	sourceFile.close();
	destinationFile.close();
}
