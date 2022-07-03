#include "tablemodel.h"
#include <qpixmap.h>
#include <QMessageBox>

TableModel::TableModel(const QVector<Entry>& entries, QObject* parent)
    : QAbstractTableModel(parent),
    entries(entries)
{
}

TableModel::TableModel(QObject* parent)
    : QAbstractTableModel(parent)
{
}

int TableModel::rowCount(const QModelIndex& parent) const
{
    return parent.isValid() ? 0 : entries.size();
}

int TableModel::columnCount(const QModelIndex& parent) const
{
    return parent.isValid() ? 0 : 4;
}

QVariant TableModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= entries.size() || index.row() < 0)
        return QVariant();

    const auto& entry = entries.at(index.row());

    if (role == Qt::DecorationRole)
    {
        switch (index.column()) {
        case 0:
            if (QFile::exists(entry.showcasephoto))
                return QImage(entry.showcasephoto).scaled(135, 135, Qt::KeepAspectRatio);
        default:
            break;
        }
    }

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0:
            if (!QFile::exists(entry.showcasephoto))
                return entry.showcasephoto;
            else return "";
        case 1:
            return entry.songname;
        case 2:
            return entry.songauthor;
        case 3:
            return entry.songduration;
        default:
            break;
        }
    }

    if (role == Qt::ToolTipRole) {
        switch (index.column()) {
        case 0:
            return entry.showcasephoto;
        default:
            break;
        }
    }
    return QVariant();
}

bool TableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        const int row = index.row();
        auto entry = entries.value(row);

        switch (index.column()) {
        case 0:
            entry.showcasephoto = value.toString();
            break;
        case 1:
            entry.songname = value.toString();
            break;
        case 2:
            entry.songauthor = value.toString();
            break;
        case 3: 
            entry.songduration = value.toString();
            break;
        default:
            return false;
        }
        entries.replace(row, entry);
        emit dataChanged(index, index, { Qt::DisplayRole, Qt::EditRole, Qt::DecorationRole });

        return true;
    }
    if (index.isValid() && role == Qt::DecorationRole) {
        const int row = index.row();
        auto entry = entries.value(row);

        switch (index.column()) {
        case 0:
            entry.showcasephoto = value.toString();
            break;
        default:
            return false;
        }
        entries.replace(row, entry);
        emit QAbstractItemModel::dataChanged(index, index, { Qt::DecorationRole });

        return true;
    }

    return false;
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Photo");
        case 1:
            return tr("Song Name");
        case 2:
            return tr("Author's Name");
        case 3:
            return tr("Song Duration");
        default:
            break;
        }
    }
    return QVariant();
}

bool TableModel::insertRows(int position, int rows, const QModelIndex& index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        entries.insert(position, { QString(), QString(), QString(), QString() });

    endInsertRows();
    return true;
}

bool TableModel::removeRows(int position, int rows, const QModelIndex& index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        entries.removeAt(position);

    endRemoveRows();
    return true;
}

Qt::ItemFlags TableModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

const QVector<Entry>& TableModel::getEntries() const
{
    return entries;
}