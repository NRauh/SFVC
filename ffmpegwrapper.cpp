#include "ffmpegwrapper.h"

FFMpegWrapper::FFMpegWrapper() {
}

void FFMpegWrapper::runConverter() {
	/*
	QString *command = new QString("./ffmpeg -i \"");
	command->append(inputPath);
	command->append("\" \"");

	command->append(outputPath);
	command->append(fileName);
	command->append(".");
	command->append(fileType);
	command->append("\"");
	*/
	QString command = QString("./ffmpeg -i %1 %2/%3.%4").arg(inputPath, outputPath, fileName, fileType);

	//system(command->toStdString().c_str());
}
