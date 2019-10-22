#pragma once

#include "rocksdb/db.h"
#include "rocksdb/options.h"

class JJrocksdb
{
	rocksdb::DB *db;
public:
	JJrocksdb();
	~JJrocksdb();

public:
	bool Open();
	void Test();
};

