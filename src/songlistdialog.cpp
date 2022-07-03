#include "songlistdialog.h"

#include "songdialog.h"
#include "ui_songlistdialog.h"
#include "tablemodel.h"
#include <QModelIndex>
#include <QMessageBox>

SongListDialog::SongListDialog(QWidget* parent) : QDialog(parent)
{
	QString fileName = "listsave.txt";
	m_ui = new Ui::SongListDialog();
	m_ui->setupUi(this);

	tableModel = new TableModel();

	m_ui->tableView->setModel(tableModel);
	m_ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
	m_ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	m_ui->tableView->setWordWrap(1);

	QFile file(fileName);

	if (file.open(QIODevice::ReadOnly))
	{
		QVector<Entry> entries;
	    QDataStream in(&file);
	    in >> entries;

		if (!entries.isEmpty())
		{
			for (const auto& entry : qAsConst(entries))
				addEntry(entry.showcasephoto, entry.songname, entry.songauthor, entry.songduration);

		}
	}
}

SongListDialog::~SongListDialog()
{
	delete m_ui;
	delete tableModel;
}

void SongListDialog::on_btnCreate_clicked()
{
	SongDialog dlg;
	
	if (dlg.exec())
	{
		addEntry(dlg.imagedir(), dlg.name(), dlg.authorname(), dlg.songduration());
		m_ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
	}
}

void SongListDialog::on_btnEdit_clicked()
{
	SongDialog dlg;
	editEntry();
}

void SongListDialog::addEntry(const QString& showcasephoto, const QString& songname, const QString& songauthor, const QString& songduration)
{
	if (!tableModel->getEntries().contains({ showcasephoto, songname, songauthor, songduration })) {
		tableModel->insertRows(0, 1, QModelIndex());

		QModelIndex index = tableModel->index(0, 0, QModelIndex());
		tableModel->setData(index, showcasephoto, Qt::EditRole);
		index = tableModel->index(0, 1, QModelIndex());
		tableModel->setData(index, songname, Qt::EditRole);
		index = tableModel->index(0, 2, QModelIndex());
		tableModel->setData(index, songauthor, Qt::EditRole);
		index = tableModel->index(0, 3, QModelIndex());
		tableModel->setData(index, songduration, Qt::EditRole);
	}
	m_ui->tableView->resizeRowsToContents();
	m_ui->tableView->resizeColumnsToContents();
}

void SongListDialog::editEntry()
{
	SongDialog dlg;

	QItemSelectionModel* selectionModel = m_ui->tableView->selectionModel();

	const QModelIndexList indexes = selectionModel->selectedRows();
	QDir imagepath;
	QString songname;
	QString songauthor;
	QString songduration;
	int row = -1;

	QModelIndex index = indexes.at(0);
	row = index.row();

	index = tableModel->index(row, 0, QModelIndex());
	QVariant varName = tableModel->data(index, Qt::ToolTipRole);
	imagepath = varName.toString();

	index = tableModel->index(row, 1, QModelIndex());
	varName = tableModel->data(index, Qt::DisplayRole);
	songname = varName.toString();

	index = tableModel->index(row, 2, QModelIndex());
	varName = tableModel->data(index, Qt::DisplayRole);
	songauthor = varName.toString();

	index = tableModel->index(row, 3, QModelIndex());
	varName = tableModel->data(index, Qt::DisplayRole);
	songduration = varName.toString();

	dlg.establishdata(imagepath, songname, songauthor, songduration);
	if (dlg.exec())
	{
		if (dlg.comparedata(imagepath, songname, songauthor, songduration) == 0)
		{
			index = tableModel->index(row, 0, QModelIndex());
			tableModel->setData(index, dlg.imagedir(), Qt::DecorationRole);
			tableModel->data(index, Qt::DecorationRole);

			index = tableModel->index(row, 1, QModelIndex());
			tableModel->setData(index, dlg.name(), Qt::EditRole);

			index = tableModel->index(row, 2, QModelIndex());
			tableModel->setData(index, dlg.authorname(), Qt::EditRole);

			index = tableModel->index(row, 3, QModelIndex());
			tableModel->setData(index, dlg.songduration(), Qt::EditRole);
		}
	}
}

void SongListDialog::on_btnSave_clicked()
{
	QFile file("listsave.txt");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		return;
	}

	QDataStream out(&file);
	out << tableModel->getEntries();	
}