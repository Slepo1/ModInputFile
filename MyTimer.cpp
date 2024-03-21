#include "MyTimer.h"

MyTimer::MyTimer(QObject *parent)
	: QAbstractItemModel(parent)
{
}

QVariant MyTimer::headerData(int section, Qt::Orientation orientation, int role) const
{
	// FIXME: Implement me!
}

QModelIndex MyTimer::index(int row, int column, const QModelIndex &parent) const
{
	// FIXME: Implement me!
}

QModelIndex MyTimer::parent(const QModelIndex &index) const
{
	// FIXME: Implement me!
}

int MyTimer::rowCount(const QModelIndex &parent) const
{
	if (!parent.isValid())
		return 0;

	// FIXME: Implement me!
}

int MyTimer::columnCount(const QModelIndex &parent) const
{
	if (!parent.isValid())
		return 0;

	// FIXME: Implement me!
}

QVariant MyTimer::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	// FIXME: Implement me!
	return QVariant();
}
