#include "stdafx.h"
#include "AdapterAbstract.h"


AdapterAbstract::AdapterAbstract()
{
}


AdapterAbstract::~AdapterAbstract()
{
}

string AdapterAbstract::formatMessage(const string &msg)
{
	return author + ": " + msg;
}

void AdapterAbstract::Configure(const ConfigMap &config)
{
	if (config.find("author") != config.cend())
	{
		SetAuthor(config.find("author")->second);
	}
}

const string &AdapterAbstract::GetAuthor() const
{
	return author;
}

void AdapterAbstract::SetAuthor(const string author)
{
	this->author = author;
}