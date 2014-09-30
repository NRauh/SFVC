#ifndef FFMPEGWRAPPER_H
#define FFMPEGWRAPPER_H

#include <QString>
#include <QDir>

class FFMpegWrapper
{
public:
	FFMpegWrapper();

	void runConverter();

	QString inputPath;
	QString outputPath;
	QString fileType;
	QString fileName;
};

#endif // FFMPEGWRAPPER_H
