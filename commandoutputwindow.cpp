#include "commandoutputwindow.h"
#include "ui_commandoutputwindow.h"

CommandOutputWindow::CommandOutputWindow(QWidget *parent) : QDialog(parent), ui(new Ui::CommandOutputWindow) {
	ui->setupUi(this);
	this->setGeometry(30, 30, this->width(), this->height());
}

CommandOutputWindow::~CommandOutputWindow() {
	delete ui;
}

void CommandOutputWindow::addToOutput(char *message) {
	ui->outputBox->appendPlainText(message);
}

void CommandOutputWindow::addToOutput(QString &message) {
	ui->outputBox->appendPlainText(message);
}

void CommandOutputWindow::on_pushButton_clicked() {
	this->close();
}
