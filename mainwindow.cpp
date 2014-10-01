#include "mainwindow.h"
#include "ui_mainwindow.h"



/***
 * In the constructor, UI is being setup, and wrapper is creating a new FFMpegWrapper
***/
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	wrapper = new FFMpegWrapper();
}



/***
 * Descontructor for MainWindow
***/
MainWindow::~MainWindow() {
	delete ui;
}



/***
 * When the runCommand button is clicked, I'm running the start method for the wrapper.
 * start() creates a new thread and runs the wrapper's run command.
 *
 * TODO: Memory management, obviously
***/
void MainWindow::on_runCommand_clicked() {
	wrapper->start();
}



/***
 * When the inputSelectButton is clicked, first I'm creating a new QFileInfo object,
 * called fileInfo, which is given the file path via QFileDialog.
 * When fileInfo is created, the inputPath textfield is set to the file to be converted's path,
 * so people can see what the file is.
 *
 * Then I move on to set wrapper.inputPath to the selected file's path,
 * and wrapper.fileName to the selected files name without extension
***/
void MainWindow::on_inputSelectButton_clicked() {
	QFileInfo *fileInfo = new QFileInfo(QFileDialog::getOpenFileName(this, tr("Select File"), "/", tr("Image Files (*)")));
	ui->inputPath->setText(fileInfo->filePath());
	wrapper->inputPath = fileInfo->filePath();
	wrapper->fileName = fileInfo->baseName();
}




/***
 * When the outPathButton is clicked, the path for output is set.
 * First the outputPath QString is created via QFileDialog which only selectes directories.
 * outPath textfield text is set to the path of the output directory,
 * and wrapper.outputPath is also set to the selected output path.
***/
void MainWindow::on_outPathButton_clicked() {
	QString outputPath = QFileDialog::getExistingDirectory(this, tr("Select Destination"), "/");
	ui->outPath->setText(outputPath);
	wrapper->outputPath = outputPath;
}



/***
 * When the combobox is changed, this function gives the text of the item.
 * Then wrapper.fileType is set to arg1 / selection.
***/
void MainWindow::on_formatSelection_currentIndexChanged(const QString &arg1) {
	wrapper->fileType = arg1;
}
