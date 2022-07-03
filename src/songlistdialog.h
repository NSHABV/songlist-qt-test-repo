#pragma once
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "tablemodel.h"

namespace Ui 
{
class SongListDialog;
}


class SongListDialog : public QDialog 
{
Q_OBJECT

public:
	SongListDialog(QWidget *parent = nullptr);
	void SongListDialog::addEntry(const QString& showcasephoto, const QString& songname, const QString& songauthor, const QString& songduration);
	void SongListDialog::editEntry();
	~SongListDialog();
public slots:
	void on_btnCreate_clicked();
	void on_btnEdit_clicked();
	void on_btnSave_clicked();
private:
	Ui::SongListDialog* m_ui = nullptr;
	TableModel* tableModel = nullptr;
};