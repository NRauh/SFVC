#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	wrapper = new FFMpegWrapper();
	wrapper->fileType = "avi";
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::on_runCommand_clicked() {
	wrapper->runConverter();
}

void MainWindow::on_inputSelectButton_clicked() {
	QFileInfo *fileInfo = new QFileInfo(QFileDialog::getOpenFileName(this, tr("Select File"), "/", tr("Image Files (*)")));
	ui->inputPath->setText(fileInfo->filePath());
	wrapper->inputPath = fileInfo->filePath();
	wrapper->fileName = fileInfo->baseName();
}

void MainWindow::on_outPathButton_clicked() {
	QString outputPath = QFileDialog::getExistingDirectory(this, tr("Select Destination"), "/");
	ui->outPath->setText(outputPath);
	wrapper->outputPath = outputPath;
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1) {
	wrapper->fileType = arg1;
}
