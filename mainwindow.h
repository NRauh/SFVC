#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFileInfo>
#include "ffmpegwrapper.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_inputSelectButton_clicked();
	void on_outPathButton_clicked();
	void on_runCommand_clicked();
	void on_formatSelection_currentIndexChanged(const QString &arg1);

	void on_nameInput_textChanged(const QString &arg1);

private:
	Ui::MainWindow *ui;
	FFMpegWrapper *wrapper;
};

#endif // MAINWINDOW_H
