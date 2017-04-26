# main.cpp NLPIR.h libNLPIR.so 均在同一目录下
# 修改main.cpp中查找NLPIR.h的路径（NLPIR.h会通过系统查找libNLPIR.so，不用人为干预）
# 修改main.cpp中查找Data文件的路径，分词系统需要使用的规则均在Data目录下
# 系统只需要
# 	Data目录以及目录中的内容
# 	main.cpp NLPIR.h libNLPIR.so Makefile四个文件
# 	生成可执行main文件后，需要添加环境变量 export LD_LIBRARY_PATH=$(pwd) 编译环境和执行环境并相同
test: main.cpp NLPIR.h
	g++ main.cpp   -L. -lpthread -L. -lNLPIR -Wall -Wunused -O3 -DOS_LINUX -o main

