#ifndef FFMPEGWRAPPER_H
#define FFMPEGWRAPPER_H

#include <QThread>
#include <QString>
#include <QDir>

class FFMpegWrapper : public QThread {
	Q_OBJECT
public:
	FFMpegWrapper(QObject *parent = 0);

	void run();

	QString inputPath;
	QString outputPath;
	QString fileType;
	QString fileName;
};

#endif // FFMPEGWRAPPER_H
