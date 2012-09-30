#pragma once

#pragma warning(push, 0)
#include <QIODevice>
#pragma warning(pop)

namespace logging
{
namespace impl
{

class writer_device : public QIODevice
{
	Q_DISABLE_COPY(writer_device);

public:
	writer_device();
	~writer_device();

protected:
	virtual qint64 readData(char*, qint64) override;
	virtual qint64 writeData(const char* data, qint64 maxSize);
};

} // impl
} // logging