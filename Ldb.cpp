#include "Ldb.h"
#include <iostream>


Ldb::Ldb()
{
	this->db = nullptr;
}


Ldb::~Ldb()
{
	if (this->db != nullptr) {
		delete db;
	}
}


bool Ldb::Open() {
	leveldb::Options options;
	options.create_if_missing = true;
	leveldb::Status status = leveldb::DB::Open(options, "./test", &db);
	bool ok = status.ok();
	assert(ok);
	return ok;
}

void Ldb::Test() {
	std::string key = "people";
	std::string value = "jason";
	std::string value1;
	leveldb::Status s = db->Put(leveldb::WriteOptions(), key, value);
	if (s.ok()) {
		s = db->Get(leveldb::ReadOptions(), key, &value1);
	}
	if (s.ok()) {
		std::cout << value1 << std::endl;
	}

	{
		leveldb::Iterator *it = db->NewIterator(leveldb::ReadOptions());
		for (it->SeekToFirst(); it->Valid(); it->Next()) {
			std::cout << it->key().ToString() << it->value().ToString() << std::endl;
		}
		assert(it->status().ok());
		delete it;
	}
}