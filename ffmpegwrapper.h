#ifndef FFMPEGWRAPPER_H
#define FFMPEGWRAPPER_H

#include <QThread>
#include <QString>
#include <QDir>
#include <QDebug>
#include "commandoutputwindow.h"

class FFMpegWrapper : public QThread {
	Q_OBJECT
public:
	FFMpegWrapper(QObject *parent = 0);

	void run();

	CommandOutputWindow outputWindow;

	QString formats[9];

	QString commandFrom;
	QString inputPath;
	QString outputPath;
	QString fileType;
	QString fileName;
	int quality;
};

#endif // FFMPEGWRAPPER_H
