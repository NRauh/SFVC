#include "ffmpegwrapper.h"
#include <stdio.h>
#include <QDebug>

FFMpegWrapper::FFMpegWrapper(QObject *parent) : QThread(parent) {
	inputPath = "";
	outputPath = "/";
	fileName = "SFVC-Video";
	fileType = "avi";
}

void FFMpegWrapper::run() {
	QString command;
	command = QString("./ffmpeg -i %1 %2/%3.%4").arg(inputPath, outputPath, fileName, fileType);


	FILE *executedCommand;
	char lineOutput[2048];

	//executedCommand = popen(command.toStdString().c_str(), "r");
	executedCommand = popen("sleep 8 && echo done", "r");


	while (fgets(lineOutput, sizeof(path)-1, executedCommand)) {
		qDebug() << lineOutput;
	}

	pclose(executedCommand);
}
