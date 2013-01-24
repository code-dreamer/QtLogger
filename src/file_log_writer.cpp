#pragma warning(push, 0)
#pragma warning(disable: 4350)
#include <QString>

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#ifndef _INC_WINDOWS
	#include <Windows.h>
#endif
#pragma warning(pop)

#include "logger/file_log_writer.h"
#include "logger/impl/utils.h"


namespace logging {

file_log_writer::file_log_writer(const QString& fileName)
{
	CHECK_QSTRING(fileName);
  
	setFileName(fileName);
}

file_log_writer::~file_log_writer()
{
	closeFile();
}

QString file_log_writer::fileName() const
{
  QMutexLocker locker(&log_file_mutex_);
  return log_file_.fileName();
}

void file_log_writer::setFileName(const QString& filename)
{
	CHECK_QSTRING(filename);

	QMutexLocker locker(&log_file_mutex_);
	if (log_file_.isOpen()) {
		log_file_.close();
	}

	log_file_.setFileName(filename);
}

bool file_log_writer::openFile()
{
	if (log_file_.isOpen()) {
		return true;
	}

	bool is_open = false;

	if (!log_file_.isOpen()) {
		if (log_file_.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
			log_stream_.setDevice(&log_file_);
			is_open = true;
		}
	}

	return is_open;
}

void file_log_writer::do_write(const QString& log_entry)
{
	QMutexLocker locker(&log_file_mutex_);

	if (openFile()) {
		log_stream_ << log_entry;
		log_stream_.flush();
		log_file_.flush();
	}
}

void file_log_writer::closeFile()
{
	QMutexLocker locker(&log_file_mutex_);
	log_file_.close();
}

} // namespace logging
