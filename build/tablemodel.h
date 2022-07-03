#pragma once
#include <QAbstractTableModel>
#include <QString>
#include <QDir>

const int COLS = 4;
const int ROWS = 1;

struct Entry
{
    QString showcasephoto;
    QString songname;
    QString songauthor;
    QString songduration;

    bool operator==(const Entry& other) const
    {
        return showcasephoto == other.showcasephoto && songname == other.songname && songauthor == other.songauthor && songduration == other.songduration;
    }
};

inline QDataStream& operator<<(QDataStream& stream, const Entry& entry)
{
    return stream << entry.showcasephoto << entry.songname << entry.songauthor << entry.songduration;
}

inline QDataStream& operator>>(QDataStream& stream, Entry& entry)
{
    return stream >> entry.showcasephoto >> entry.songname >> entry.songauthor >> entry.songduration;
}

class TableModel : public QAbstractTableModel
{
public:
    TableModel(QObject* parent = nullptr);
    TableModel(const QVector<Entry>& entries, QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    bool insertRows(int position, int rows, const QModelIndex& index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex& index = QModelIndex()) override;
    const QVector<Entry>& getEntries() const;
    void TableModel::saveData(const QString& fileName);
private:
    QVector<Entry> entries;
signals:
    void editCompleted(const QString&);
};