#include "ffmpegwrapper.h"

FFMpegWrapper::FFMpegWrapper() {
	outputPath = new QString("/");
	filetype = new QString("avi");
}

void FFMpegWrapper::setInputPath(QString *newPath) {
	inputPath = newPath;
}

void FFMpegWrapper::setOutputPath(QString *newOutPath) {
	outputPath = newOutPath;
}

void FFMpegWrapper::setFileType(QString *newFiletype) {
	filetype = newFiletype;
}
