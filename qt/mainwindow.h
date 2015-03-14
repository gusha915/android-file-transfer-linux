#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <mtp/ptp/Device.h>

namespace Ui {
class MainWindow;
}

class MtpObjectsModel;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	void showEvent(QShowEvent *e);
	void keyPressEvent ( QKeyEvent * event );

private slots:
	void back();
	void onActivated ( const QModelIndex & index );
	void customContextMenuRequested ( const QPoint & pos );

private:
	Ui::MainWindow *	_ui;
	MtpObjectsModel *	_objectModel;
	QVector<mtp::u32>	_history;

	mtp::DevicePtr		_device;
};

#endif // MAINWINDOW_H