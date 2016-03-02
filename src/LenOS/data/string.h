#ifndef __STRING__
#define __STRING__

#include "com.h"
#include "vector.h"

class String
{
	private:
		Vector<char> vStr;
		//static char str[128];
		
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		
	public:
		String();
		String(const String&);
		String(const char*);
		String(const_iterator beg, const_iterator end);
		~String() { vStr.clear(); }
		
		static String format(const char* format, ...);
		
		char& 	operator[](U32 index);
		String 	operator+(String& str);
		bool 		operator==(String&);
		bool 		operator==(const char*);
		String& operator=(String&);
		
		char* 	c_str();
		
		iterator begin()  const;
		iterator end() const;
		
		U32 size() const;
};



#endif
