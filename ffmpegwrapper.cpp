#include "ffmpegwrapper.h"
#include <stdio.h>
#include <QDebug>



/***
 * In the constructor, I'm giving the variables default values,
 * incase they don't change.
***/
FFMpegWrapper::FFMpegWrapper(QObject *parent) : QThread(parent) {
	inputPath = "";
	outputPath = "/";
	fileName = "SFVC-Video";
	fileType = "avi";
	quality = 1;
}



/***
 * run is an override function that gets exicuted with FFMpegWrapper::start()
 * First a QString variable called command is created, which is first set to run ffmpeg.
 * The different parts of the command that'll run are appended to the command string individually.
 *
 * After command is made, a FILE variable is made called executedCommand, and
 * lineOutput is created as a char buffer.
 * executedCommand is set to popen() which takes a char* (hence the stuff with command)
 * and set to read.
 * The while loop uses fgets to run the command and also read the printed line
 *
 * TODO: Make a window that shows the output
***/
void FFMpegWrapper::run() {
	QString command;
	command = QString("./ffmpeg");

	command.append(QString(" -i \"%1\"").arg(inputPath));
	command.append(QString(" -qscale %1").arg(quality));
	command.append(QString(" \"%1/%2.%3\"").arg(outputPath, fileName, fileType));

	outputWindow.show();

	FILE *executedCommand;
	char lineOutput[2048];

	command.append(" 2>&1");
	executedCommand = popen(command.toStdString().c_str(), "r");


	while (fgets(lineOutput, sizeof(lineOutput)-1, executedCommand)) {
		qDebug() << lineOutput;
		// commented out because, the amount could crash the program.
		//outputWindow.addToOutput(lineOutput);
	}

	pclose(executedCommand);
}
