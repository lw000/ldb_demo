// ldb_demo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#define GOOGLE_GLOG_DLL_DECL           // 使用静态glog库用这个
#define GLOG_NO_ABBREVIATED_SEVERITIES // 没这个编译会出错,传说因为和Windows.h冲突

#include <iostream>
#include <fstream>

#include <glog/logging.h>


#include "Ldb.h"
#include "JJrocksdb.h"
#include "JJson.h"


int main(int argc, char **argv)
{   
	google::InstallFailureSignalHandler();
	google::InitGoogleLogging(argv[0]);

	LOG(INFO) << "GLOG test..." << std::endl;

	{
		Ldb db;
		if (db.Open()) {
			db.Test();
		}
	}

	{
		JJrocksdb db;
		if (db.Open()) {
			db.Test();
		}
	}

	{
		JJson j;
		j.Test();
	}

}
