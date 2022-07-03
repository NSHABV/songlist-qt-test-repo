#pragma once
#include <QPainter>
#include <QApplication>
#include <qstyleditemdelegate.h>

class Delegate : public QStyledItemDelegate
{
public: 
    Delegate(QObject* parent = nullptr);
    void Delegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
};