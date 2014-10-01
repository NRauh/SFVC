#include "ffmpegwrapper.h"

FFMpegWrapper::FFMpegWrapper() {
	inputPath = "";
	outputPath = "/";
	fileName = "SFVC-Video";
	fileType = "avi";
}

void FFMpegWrapper::runConverter() {
	QString command;
	command = "./ffmpeg -i %1 %2/%3.%4";
	command.arg(inputPath, outputPath, fileName, fileType);

	system(command.toStdString().c_str());
}
