#pragma once

#pragma warning(push, 0)
#pragma warning(disable: 4350)
#include <QFile>
#include <QTextStream>
#pragma warning(pop)

#include "logger/log_writer_base.h"

namespace logging {

class LOGGER_EXPORT file_log_writer : public log_writer_base
{
	Q_DISABLE_COPY(file_log_writer)

public:
	file_log_writer(const QString& file_name);
	virtual ~file_log_writer();

public:
	QString fileName() const;
	void setFileName(const QString&);

protected:
   virtual void do_write(const QString& log_entry) override;
   
   bool openFile();
   void closeFile();

private:
	QFile log_file_;
	QTextStream log_stream_;
	mutable QMutex log_file_mutex_;
};

} // namespace logging