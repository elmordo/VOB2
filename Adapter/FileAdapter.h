#pragma once

#include <fstream>

#include "AdapterAbstract.h"

class FileAdapter : public AdapterAbstract
{

	ofstream output;

public:
	FileAdapter();

	virtual ~FileAdapter();

	virtual void Configure(const ConfigMap config);

	virtual void SendMessage(const string &msg);
};

