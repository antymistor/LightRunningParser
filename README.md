This is an extremely lightweight real-time program analysis runner


这是一个极其轻量的、跨平台的运行期代码解释器，核心代码（LRP目录）少于200行。
可用于对伪代码在运行期解释并执行。
伪代码的的语法与汇编类似，但是只保留了核心的16条原子指令，通过这16条指令可以实现绝大多数C99支持的朴素逻辑。
伪代码所描述的输入输出以及所需的中间内存，都泛化为一块内存buffer,伪代码用于定义对这片内存buffer的操作。
具体的api使用示例可见main.cpp，核心api定义在 LRP_buffer.h ,LRP_processer.h中

Demo use Step:
            cd LightRunningParser
            mkdir build
            cd build
            cmake ..
            make
            cp ../origin.txt origin.txt
            ./LRP

