#include "errordialog.h"
#include "ui_errordialog.h"

ErrorDialog::ErrorDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ErrorDialog) {
	ui->setupUi(this);
}

ErrorDialog::~ErrorDialog() {
	delete ui;
}

/***
 * setErrorMessage provides a way to set the text of the error message
***/
void ErrorDialog::setErrorMessage(char *message) {
	ui->errorMessage->setText(message);
}
