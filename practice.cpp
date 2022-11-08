# include <iostream>
# include <sstream>
# include <exception>

class MyException : public std :: exception
{
	public :
		MyException (const std::string& msg , const std::string& file , int line)
		{
			std :: ostringstream oss;
			oss << file << ": line " << line << ": " << msg;
			msg_ = oss.str();
		}
		virtual const char* what() const noexcept
		{
			return msg_.c_str();
		}
	private :
		std :: string msg_;
};

int main ()
{
	try
	{
		throw MyException ("exception test", __FILE__ , __LINE__ );
	}
	catch (const std::exception& e)
	{
		std :: cerr << e.what () << std::endl;
	}
}