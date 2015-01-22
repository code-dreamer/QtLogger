## QtLogger
Lightweight qt logger.

#### Usage

```
using namespace logging;

// add appenders
file_log_writer* file_log = new file_log_writer("test_log.txt");
debug_writer* debug_writer = new debug_writer();
single_logger()->add_log_writer(file_log);
single_logger()->add_log_writer(debug_writer);

// log level
single_logger()->set_log_level(log_level::debug_level);

// start logging
int val = 1;
QString str = "str";
LOG_DEBUG() << "val = " << val << ", str = " << str;

// logging with module name
const char first_lib_id_str[] = "first_lib_id";
LIB_LOG_DEBUG(first_lib_id_str) << "val = " << val << ", str = " << str;
```

**custom object**
```
class CustomObject
{
public:
	CustomObject() {}
	int GetValue() const { return m_val; }

private:
	int m_val{10};
};

QDebug operator<<(QDebug stream, const CustomObject& obj)
{
	return stream << "Custom value =" << obj.GetValue();
}

CustomObject obj;
LOG_WARNING() << obj;
```
