#include "JJson.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

JJson::JJson()
{
}


JJson::~JJson()
{
}


void JJson::Test() {
	nlohmann::json j;
	j["name"] = "levi";
	j["age"] = 10;
	j["sex"] = true;
	j["account"]["name"] = "levi";
	j["account"]["name"] = "levi";
	j["account"]["age"] = 10;
	j["account"]["sex"] = true;
	j["list"] = { 0,1,2,3,4,5,6,7,8,9 };
	std::string s = j.dump();
	std::cout << s << std::endl;

	nlohmann::json object = nlohmann::json::parse(s);
	std::string s1 = j.dump(4);
	std::cout << s1 << std::endl;
	{
		std::ifstream f("conf.json");
		nlohmann::json object = nlohmann::json::parse(f);
		std::string name = object["name"].get<std::string>();
		int age = object["age"].get<int>();
		bool sex = object["sex"].get<bool>();
		{
			auto v = object["list"];
			int ss = v[0].get<int>();
			int ss1 = v[1].get<int>();
			for (nlohmann::json::iterator it = v.begin(); it != v.end(); ++it) {
				std::cout << *it << std::endl;
			}
		}
		std::string s2 = j.dump(4);
		std::cout << s2 << std::endl;
	}
	{
		std::vector<int> lst = { 1,2,3,4,5,6,7,8,9 };
		nlohmann::json jj(lst);
		std::string s2 = jj.dump(4);
		std::cout << s2 << std::endl;
	}
	{
		nlohmann::json jj = R"({"compact": true, "schema": 0})"_json;
		std::vector<std::uint8_t> v_bson = nlohmann::json::to_bson(jj);
		for (auto v : v_bson) {
			std::cout << v << " ";
		}
	}
	{
		std::string sss = u8"(ÀîÎ°)";
		std::cout << sss << std::endl;
	}
}