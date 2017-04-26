#include <cstdio>
#include <string>
#include "./NLPIR.h"

using namespace std;

// 查找Data目录
const string DataPath = "../";

int main(void)
{
	if (NLPIR_Init(DataPath.c_str(), 1, ""))
		// NLPIR_Init中第二个参数表示使用的编码规则
		// 1 	uft8
		// 0	gb
	{
		printf("初始化成功");
		printf("\n\n");
	}
	else
	{
		printf("初始化失败\n");
		printf("按任意键退出...\n");
		getchar();
		return 0;
	}

	string sSrc = "哈尔滨天气不错";

	printf("原文: %s", sSrc.c_str());
	printf("\n\n");

	// 词频统计
	string wordFreq = NLPIR_WordFreqStat(sSrc.c_str());
	printf("词频结果如下：%s", wordFreq.c_str());
}
