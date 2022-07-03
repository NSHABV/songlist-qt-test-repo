#include "songdialog.h"
#include "ui_songdialog.h"
#include <QFileDialog>
#include <QIntValidator>

SongDialog::SongDialog(QWidget* parent): QDialog(parent), m_ui(new Ui::SongDialog())
{
	m_ui->setupUi(this);

	connect(m_ui->btnPreview, &QPushButton::clicked, this, &SongDialog::choosePreview);
	QDir dir;
	if (!dir.exists(m_imageDir))
		dir.mkpath(m_imageDir);
	QRegExpValidator* numvalidator = new QRegExpValidator(QRegExp("[0-9]*"), this);
	m_ui->durationLineEdit->setValidator(numvalidator);
}

SongDialog::~SongDialog()
{
	delete m_ui;
}

void SongDialog::choosePreview()
{
	const auto filename = QFileDialog::getOpenFileName(this, tr("Выберите изображение"),
		QString(), "(*.jpeg *.jpg *png *gif)");
	if (filename.isEmpty())
		return;
	imageDir = filename;
	const QString copyName = copiedPreview(filename);
	showPreview(copyName);
}

QString SongDialog::copiedPreview(const QString& filePath) const
{
	const QImage image(filePath);
	const auto smaller = image.scaled(m_ui->labelPreview->width(), m_ui->labelPreview->height(),
		Qt::AspectRatioMode::KeepAspectRatioByExpanding);

	QString name = "1.png";
	if (!smaller.save(fullImagePath(name), "PNG"))
		return QString();

	return  name;
	
}

void SongDialog::showPreview(const QString& relativePath) const
{
	if (relativePath.isEmpty())
		return;
	const auto fn = fullImagePath(relativePath);
	if (!QFile::exists(fn))
		return;

	const QPixmap pixmap(fn);	
	m_ui->labelPreview->setPixmap(pixmap);
}


QString SongDialog::fullImagePath(const QString& relativePath) const
{
	QDir dir;
	dir.cd(m_imageDir);
	return dir.absoluteFilePath(relativePath);
}

QString SongDialog::name()
{
	return this->m_ui->lineEdit->text();
}

QString SongDialog::authorname()
{
	return this->m_ui->authorLineEdit->text();
}

QString SongDialog::songduration()
{
	return this->m_ui->durationLineEdit->text();
}

QString SongDialog::imagedir()
{
	return imageDir;
}

void SongDialog::establishdata(QDir editPath, QString editsongName, QString editauthorName, QString editsongDur)
{
	QPixmap pixmap(editPath.path());
	this->m_ui->lineEdit->setText(editsongName);
	this->m_ui->authorLineEdit->setText(editauthorName);
	this->m_ui->durationLineEdit->setText(editsongDur);
	imageDir = editPath.path();
	pixmap = pixmap.scaled(m_ui->labelPreview->width(), m_ui->labelPreview->height(),
		Qt::AspectRatioMode::KeepAspectRatioByExpanding);
	m_ui->labelPreview->setPixmap(pixmap);
}

bool SongDialog::comparedata(QDir editPath, QString editsongName, QString editauthorName, QString editsongDur)
{
	if (imageDir != editPath.path() || this->m_ui->lineEdit->text() != editsongName || this->m_ui->authorLineEdit->text() != editauthorName
		|| this->m_ui->durationLineEdit->text() != editsongDur)
		return 0;
	else
	    return 1;
}