#ifndef FFMPEGWRAPPER_H
#define FFMPEGWRAPPER_H

#include <QThread>
#include <QString>
#include <QDir>
#include <QDebug>
#include <stdio.h>
#include "errordialog.h"

class FFMpegWrapper : public QThread {
	Q_OBJECT
public:
	FFMpegWrapper(QObject *parent = 0);

	void run();
	void stopCommand();

	QString formats[9];

	QString commandFrom;
	QString inputPath;
	QString outputPath;
	QString fileType;
	QString fileName;
	int quality;

private:
	ErrorDialog errWindow;
	void showErrWindow(char *message);
	bool commandShouldRun;
};

#endif // FFMPEGWRAPPER_H
