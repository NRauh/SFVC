#include "ffmpegwrapper.h"
#include <stdio.h>



/***
 * In the constructor, I'm giving the variables default values,
 * incase they don't change.
 *
 * And I'm setting the array of output formats to corrispond with the format selection.
 *
 * The if statements are for checking if there's a global install of ffmpeg, and if not
 * if there's a copy of ffmpeg next to sfvc, and it uses the first one found.
 *
 * TODO: There's probably a better way to set the formats
 * TODO: Alert if there's no copy of FFmpeg
***/
FFMpegWrapper::FFMpegWrapper(QObject *parent) : QThread(parent) {
	inputPath = "";
	outputPath = "/";
	fileName = "SFVC-Video";
	fileType = "avi";
	quality = 1;

	formats[0] = "avi";
	formats[1] = "flv";
	formats[2] = "gif";
	formats[3] = "mkv";
	formats[4] = "mov";
	formats[5] = "mp4";
	formats[6] = "mpg";
	formats[7] = "rm";
	formats[8] = "wmv";

	if (system("ffmpeg -version") == 0) {
		commandFrom = "ffmpeg";
	} else if (system("./ffmpeg -version") == 0) {
		commandFrom = "./ffmpeg";
	} else {
		qDebug() << "Not found";
	}
}



/***
 * run is an override function that gets exicuted with FFMpegWrapper::start()
 * First a QString variable called command is created, which is first set to run ffmpeg.
 * The different parts of the command that'll run are appended to the command string individually.
 *
 * After command is made, a FILE variable is made called executedCommand, and
 * lineOutput is created as a char buffer.
 * executedCommand is set to popen() which takes a char* (hence the stuff with command)
 * and set to read the output (2>&1 makes the output read stderr, which is where ffmpeg spits output).
 * The while loop uses fgets to run the command and also read the printed line
 *
 * TODO: Make a window that shows the output
***/
void FFMpegWrapper::run() {
	QString command;
	command = QString(commandFrom);

	command.append(QString(" -i \"%1\"").arg(inputPath));
	command.append(QString(" -qscale %1").arg(quality));
	command.append(QString(" \"%1/%2.%3\"").arg(outputPath, fileName, fileType));

	FILE *executedCommand;
	char lineOutput[2048];

	command.append(" 2>&1");
	executedCommand = popen(command.toStdString().c_str(), "r");


	while (fgets(lineOutput, sizeof(lineOutput)-1, executedCommand)) {
		qDebug() << lineOutput;
	}

	pclose(executedCommand);
}
