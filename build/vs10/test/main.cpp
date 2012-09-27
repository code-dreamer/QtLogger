#include <QtCore/QCoreApplication>
#include "logger/logger.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Logging::Logger ll;

	return a.exec();
}
