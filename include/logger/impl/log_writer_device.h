#pragma once

namespace Logging
{

namespace Impl
{

class LogWriterDevice : public QIODevice
{
public:
	LogWriterDevice();
	virtual ~LogWriterDevice();

public:
	QDebug& stream();

protected:
	virtual qint64 readData(char *data, qint64 maxlen) override;
	virtual qint64 writeData(const char *data, qint64 len) override;

private:
	QDebug out_stream_;
};

} // Impl

} // Logging
