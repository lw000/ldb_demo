#include "Ldb.h"
#include <iostream>

class TwoPartComparator : public leveldb::Comparator {
public:
	TwoPartComparator()
	{
	}

	~TwoPartComparator()
	{
	}

public:
	virtual int Compare(const leveldb::Slice& a, const leveldb::Slice& b) const {
		return 0;
	}

	virtual const char* Name() const {
		return "TwoPartComparator";
	}

	virtual void FindShortestSeparator(std::string* start,
		const leveldb::Slice& limit) const {

	}

	virtual void FindShortSuccessor(std::string* key) const {

	}
};

TwoPartComparator cmp;

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
	options.block_cache = leveldb::NewLRUCache(1024);
	options.create_if_missing = true;
	options.comparator = &cmp;
	leveldb::Status status = leveldb::DB::Open(options, "./test", &db);
	bool ok = status.ok();
	assert(ok);
	return ok;
}

void Ldb::Test() {
	std::string key = "people:1123";
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

	{
		leveldb::Slice s1 = "12213123123";
		std::string str = "1232112313";
		leveldb::Slice s2 = str;
		if (s2.empty()) {

		}
	}

}