// Final Project Milestone 2 - Error Class
// Version 3.4
// Error.cpp
// Date	2018-11-09
// Author Anmol Singh 147528178
// Description
// This is the implementation and definitions of the Error class
//
/////////////////////////////////////////////////////////////////

#include<iostream>
#include<cstring>
#include<string>
#include"Error.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
using namespace aid;
namespace aid
{
//this is the default constructor for the implement file
//
	Error::Error()
	{
		m_message = new char[2000];
		m_message[0] = '\0';
	}
// this constructor takes the value and set that value either to safe emty state or the value
//
	Error::Error(const char* error_message) 
	{
		if (error_message == nullptr || error_message[0] == '\0') 
		{
		m_message = nullptr;
		}
		else
		{
			m_message = new char[strlen(error_message) + 1];
			strncpy(m_message, error_message, strlen(error_message) );
                         m_message[strlen(error_message)] = '\0';
						
                   }
		
	}
// this is the default destructor and call clear to avoid code duplication
//
	Error::~Error(){
		clear();
	}
// clear function to clear the message and set it to nullptr
//
	void Error::clear()
	{
		delete[] m_message;
		m_message = nullptr;

	}
// a function which check the true and false, if message is nullptr or empty it return true
//
	bool Error::isClear() const
	{
		bool valid = true;
		if (m_message == nullptr || m_message[0]=='\0') 
		{
			return valid;
		}
		else
		{
			valid = false;
			return valid;
		}
	}
// this funtion takes the message and set that to entered one
//
	void Error::message(const char* str)
	{
		delete[] m_message;
		m_message = new char[strlen(str) +1];
		strncpy(m_message, str, strlen(str));
		m_message[strlen(str)] = '\0';
			}
// a const function that return the message
//
	const char* Error:: message()const 
	{
		return m_message; 
	}
// funtion to output the content of the code
//
	std::ostream& operator<<(std::ostream& os, const Error& em)
	{
		if (em.isClear() == false)
		{
			os << em.message();
		}
		return os;
	}
}
