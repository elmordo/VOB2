#pragma once

#include <map>
#include <string>

using namespace std;

class AdapterAbstract
{
public:

	typedef map<string, string> ConfigMap;

private:

	string author;

protected:

	string formatMessage(const string &msg);

public:
	AdapterAbstract();

	virtual ~AdapterAbstract();

	virtual void Configure(const ConfigMap &config);

	const string &GetAuthor() const;

	void SetAuthor(const string author);

	virtual void SendMessage(const string &msg) = 0;
};

