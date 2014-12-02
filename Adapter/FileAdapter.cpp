#include "stdafx.h"
#include "FileAdapter.h"


FileAdapter::FileAdapter()
{
}


FileAdapter::~FileAdapter()
{
}

void FileAdapter::Configure(const ConfigMap config)
{
	AdapterAbstract::Configure(config);

	if (config.find("fileName") != config.cend())
	{
		string fName = config.find("fileName")->second;

		output.open(fName, ios::out);
	}
}

void FileAdapter::SendMessage(const string &msg)
{
	output << formatMessage(msg) << endl;
}