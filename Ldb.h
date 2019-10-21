#pragma once

#include <leveldb/db.h>
#include <leveldb/comparator.h>
#include <leveldb/cache.h>

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

