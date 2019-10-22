#include "JJrocksdb.h"
#include <iostream>

static std::string kPath = "/tmp";

JJrocksdb::JJrocksdb()
{
	this->db = nullptr;
}


JJrocksdb::~JJrocksdb()
{
	if (this->db != nullptr) {
		delete this->db;
	}
}

bool JJrocksdb::Open() {
	rocksdb::Options options;
	options.create_if_missing = true;

	rocksdb::Status s = rocksdb::DB::Open(options, kPath, &db);

	bool ok = s.ok();
	assert(ok);

	return ok;
}

void JJrocksdb::Test() {
	rocksdb::Status s;
	s = this->db->Put(rocksdb::WriteOptions(), "key", "111111111111111");
	assert(s.ok());

	std::string v;
	s = this->db->Get(rocksdb::ReadOptions(), "key", &v);
	assert(s.ok());

	std::cout << v << std::endl;
}