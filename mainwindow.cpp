#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	wrapper = new FFMpegWrapper();
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::on_inputSelectButton_clicked() {
	QString selectedFile = QFileDialog::getOpenFileName(this, tr("Select File"), "/", tr("Image Files (*)"));
	ui->inputPath->setText(selectedFile);
	wrapper->setInputPath(&selectedFile);
}

void MainWindow::on_outPathButton_clicked() {
	QString outputPath = QFileDialog::getExistingDirectory(this, tr("Select Destination"), "/");
	ui->outPath->setText(outputPath);
	wrapper->setOutputPath(&outputPath);
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1) {
	QString fileType = arg1;
	wrapper->setFileType(&fileType);
}
