#pragma once
#include <QDialog>
#include <QDir>

namespace Ui 
{	
class SongDialog;
}

class SongDialog : public QDialog
{
	Q_OBJECT
public:
	SongDialog(QWidget* parent = nullptr);
	~SongDialog();
	QString SongDialog::name();
	QString SongDialog::imagedir();
	QString SongDialog::authorname();
	QString SongDialog::songduration();
	void SongDialog::establishdata(QDir editPath, QString editsongName, QString editauthorName, QString editsongDur);
	bool SongDialog::comparedata(QDir editPath, QString editsongName, QString editauthorName, QString editsongDur);

public slots:
private:
	void choosePreview();
	QString copiedPreview(const QString& filePath) const;
	void showPreview(const QString& relativePath) const;
	QString fullImagePath(const QString& relativePath) const;
	
	Ui::SongDialog* m_ui = nullptr;
	const QString m_imageDir = "../../images";
	QString imageDir;
};

