#pragma once

#include <leveldb/db.h>

class Ldb
{
	leveldb::DB *db;
public:
	Ldb();
	~Ldb();

public:
	bool Open();
	void Test();
};

