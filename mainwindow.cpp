#include "mainwindow.h"
#include "ui_mainwindow.h"



/***
 * In the constructor, UI is being setup, and wrapper is creating a new FFMpegWrapper,
 * and hiding the progress bar & stop button.
***/
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	wrapper = new FFMpegWrapper();
	ui->progressBar->hide();
	ui->stopConvert->hide();
}



/***
 * Descontructor for MainWindow
***/
MainWindow::~MainWindow() {
	delete ui;
	delete wrapper;
}



/***
 * When the runCommand button is clicked, I'm  showing the progress bar & stop button,
 * and hiding the start button. Then run the start method for the wrapper.
 * start() creates a new thread and runs the wrapper's run command.
 * When the wrapper emits it's finished signal, I'm hiding the progress bar, & stop button,
 * and showing the start button.
***/
void MainWindow::on_runCommand_clicked() {
	ui->progressBar->show();
	ui->stopConvert->show();
	ui->runCommand->hide();
	wrapper->start(QThread::HighestPriority);
	connect(wrapper, SIGNAL(finished()), ui->progressBar, SLOT(hide()));
	connect(wrapper, SIGNAL(finished()), ui->stopConvert, SLOT(hide()));
	connect(wrapper, SIGNAL(finished()), ui->runCommand, SLOT(show()));
}



/***
 * When the button is clicked it stops the while loop for the command.
***/
void MainWindow::on_stopConvert_clicked() {
	wrapper->stopCommand();
}



/***
 * When the inputSelectButton is clicked, first I'm creating a new QFileInfo object,
 * called fileInfo, which is given the file path via QFileDialog.
 * When fileInfo is created, the inputPath textfield is set to the file to be converted's path,
 * and the file name without extension is being put in the file name input.
 *
 * Then I move on to set wrapper.inputPath to the selected file's path,
 * and wrapper.fileName to the selected files name without extension
***/
void MainWindow::on_inputSelectButton_clicked() {
	QFileInfo *fileInfo = new QFileInfo(QFileDialog::getOpenFileName(this, tr("Select File"), "/", tr("Image Files (*)")));
	ui->inputPath->setText(fileInfo->filePath());
	ui->nameInput->setText(fileInfo->baseName());
	wrapper->inputPath = fileInfo->filePath();
	wrapper->fileName = fileInfo->baseName();

	delete fileInfo;
}


/***
 * When the text for the path changes, then it updates where ffmpeg will look
 * for the file.
***/
void MainWindow::on_inputPath_textChanged(const QString &arg1) {
	QFileInfo *fileInfo = new QFileInfo(arg1);
	wrapper->inputPath = fileInfo->filePath();
	delete fileInfo;
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
 * When the text for the output path changes, it updates where ffmpeg will
 * put the converted file at.
***/
void MainWindow::on_outPath_textChanged(const QString &arg1) {
	wrapper->outputPath = arg1;
}



/***
 * When the text in the name input field is changed (person or computer),
 * then the file name is changed for the wrapper.
***/
void MainWindow::on_nameInput_textChanged(const QString &arg1) {
	wrapper->fileName = arg1;
}



/***
 * When the combobox is changed, this function gives the number of the selection.
 * The filetype for the wrapper is set to the format at the index of the selection.
***/
void MainWindow::on_formatSelection_currentIndexChanged(int index) {
	wrapper->fileType = wrapper->formats[index];
}



/***
 * The quality selection box has six values which get lower,
 * the quality can be 1-31, so they each get worse by six.
***/
void MainWindow::on_qualitySelection_currentIndexChanged(int index) {
	switch (index) {
	case 0:
		wrapper->quality = 1;
		break;
	case 1:
		wrapper->quality = 7;
		break;
	case 2:
		wrapper->quality = 13;
		break;
	case 3:
		wrapper->quality = 19;
		break;
	case 4:
		wrapper->quality = 25;
		break;
	case 5:
		wrapper->quality = 31;
		break;
	default:
		break;
	}
}
