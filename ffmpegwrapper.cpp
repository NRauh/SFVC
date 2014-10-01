#include "ffmpegwrapper.h"

FFMpegWrapper::FFMpegWrapper(QObject *parent) : QThread(parent) {
	inputPath = "";
	outputPath = "/";
	fileName = "SFVC-Video";
	fileType = "avi";
}

void FFMpegWrapper::run() {
	QString command;
	command = QString("./ffmpeg -i %1 %2/%3.%4").arg(inputPath, outputPath, fileName, fileType);

	system(command.toStdString().c_str());
	//system("sleep 10 && echo Done");
}
