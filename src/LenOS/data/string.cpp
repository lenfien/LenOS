#include "string.h"
#include <cstdarg>

//char String::str[128];

String::String()
{
	
}

String::String(const char * str)
{
	while(*str)
	{
		vStr.push_back(*str);
		str++;
	}
	vStr.push_back(0);
}


String::String(const_iterator beg, const_iterator end)
{
	const_iterator it; 
	
	for(it = beg; it != end; it ++)
		vStr.push_back(*it);
	
	vStr.push_back(0);
}

String::String(const String& str)
{
	const_iterator it = str.begin(); 
	
	for(; it != str.end(); it ++)
		vStr.push_back(*it);
	
	vStr.push_back(0);
}

String String::format(const char *format, ...)
{
	char buffer[128];
	
	std::va_list args;
	va_start(args, format);
	
	vsprintf(buffer, format, args);
	va_end(args);
	
	String res(buffer);
	return res;
}

char& String::operator[](U32 index)
{
	return vStr[index];
}

String String::operator+(String& str)
{
	const_iterator it = str.begin() ; 
	
	vStr.erase(vStr.end() - 1);
	
	for(; it != str.end() ; it ++)
		vStr.push_back(*it);
	
	vStr.push_back(0);
	
	return *this;
}

bool String::operator==(String& str)
{
	if((vStr == str.vStr) == 0)
		return true;
		
	return false;
}


bool String::operator==(const char* str)
{
	String s(str);
	
	return s == *this;
	
}

String& String::operator=(String& str)
{
	vStr.clear();
	iterator it; 
	
	for(it = str.begin(); it != str.end(); it ++)
		vStr.push_back(*it);
	
	vStr.push_back(0);
	return *this;
}

char* String::c_str()
{
	//char *p = str;
	//for(iterator it = begin(); it <= end(); it ++)
	//	*p++ = *it;
	return vStr.begin();
}

String::iterator String::begin() const
{
	return vStr.begin();
}

String::iterator String::end() const
{
	if(vStr.empty())
		return vStr.end();
	
	return vStr.end() - 1;
}

U32 String::size() const
{
	return vStr.size() - 1;
}


