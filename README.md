### 使用

1. 使用`cd ./lib`进入lib目录
2. 使用`make`进行编译
3. 使用`./main`查看执行效果

### 说明
1. main.cpp NLPIR.h libNLPIR.so 均在同一目录下
2. 修改main.cpp中查找NLPIR.h的路径（NLPIR.h会通过系统查找libNLPIR.so，不用人为干预）
3. 修改main.cpp中查找Data文件的路径，分词系统需要使用的规则均在Data目录下
4. 系统目录结构

    ```
    a. Data目录以及目录中的内容
    b. main.cpp NLPIR.h libNLPIR.so Makefile四个文件
    c. 生成可执行main文件后，需要添加环境变量 export LD_LIBRARY_PATH=$(pwd) 编译环境和执行环境并相同
    ```

5. Makefile文件说明

    Makefile编写规则如下，g++之前的分隔符为tab
    ```
    test: <main.cpp文件目录>main.cpp <NLPIR.h文件目录>NLPIR.h
        g++ <main.cpp文件目录>main.cpp -L. -lpthread -L<libNLPIR.so文件目录> -lNLPIR -Wall -Wunused -O3 -DOS_LINUX -o main

    参数意义：
    -L. -lpthread
        从当前目录开始依次搜索libthread.so文件，此为系统文件
    -L<libNLPIR.so文件目录> -lNLPIR
        查找libNLPIR.so，此为自己的文件
    -Wall -Wunused -O3 -DOS_LINUX
        相应的参数，不懂
    -o main
        将可执行文件输出到当前目录下，命名为main
    ```

## nan

    nan可简化addon的编写

## binding.gyp

    ​```
    1. g++编译时所需的参数如何在binding.gyp中体现出来
    "cflags": ["-Wall -Wunused -O3 -DOS_LINUX"]
    
    2. libNLPIR.so要以绝对路径进行查找
    
    3. 查找NLPIR.h文件
    "include_dirs": [
        "include", "./lib"
    ],
    
    4. 如何调用函数？
        传参数
        调用函数
        返回参数
    
    ​```