#ifndef FFMPEGWRAPPER_H
#define FFMPEGWRAPPER_H

#include <QString>

class FFMpegWrapper
{
public:
	FFMpegWrapper();

	void setInputPath(QString *newPath);
	void setOutputPath(QString *newOutPath);
	void setFileType(QString *newFiletype);

private:
	QString *inputPath;
	QString *outputPath;
	QString *filetype;
};

#endif // FFMPEGWRAPPER_H
