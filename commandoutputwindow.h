#ifndef COMMANDOUTPUTWINDOW_H
#define COMMANDOUTPUTWINDOW_H

#include <QDialog>

namespace Ui {
class CommandOutputWindow;
}

class CommandOutputWindow : public QDialog
{
	Q_OBJECT

public:
	explicit CommandOutputWindow(QWidget *parent = 0);
	~CommandOutputWindow();

	void addToOutput(char *message);
	void addToOutput(QString &message);

private slots:
	void on_pushButton_clicked();

private:
	Ui::CommandOutputWindow *ui;
};

#endif // COMMANDOUTPUTWINDOW_H
