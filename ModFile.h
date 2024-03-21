#ifndef MODFILE_H
#define MODFILE_H

#include <QCoreApplication>

class ModFile
{
private:
	QString directoryPath;
	QString fileMask;
	QString newDirectory;
public:
	ModFile(QString dirPath, QString fMask); //конструктор в который мы передаем путь к файлам и маску
//	~ModeFile();
public:
	void setNewd(QString newDir); // Метод для установки директории, в которой мы будем хранить результ. файлы
	void fMaska(); // Метод для отображения файлов с маской
	void deleteFile(QString filName); // Метод для удаления файлов
	void xorFile(QString fileName, long long int xorValue); //xor для файла

};
#endif // MODFILE_H
