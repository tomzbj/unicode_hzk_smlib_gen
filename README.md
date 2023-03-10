# unicode_hzk_smlib_gen
Unicode内码的汉字库点阵小字库制作工具

如果设备需要显示的汉字很多, 或者预先不确定会显示什么字, 这时我们需要完整的点阵字库.
16点阵的HZK16有200多k, 一般得在板上加一片SPIFLASH用来存储. 
当年UCDOS之类汉字系统的字库质量很高, 相比之下取模软件取出来的效果只能说是惨不忍睹. 
但是这些字库都是按GB2312内码排列的, 因此我先把它们改为Unicode顺序排列.

(HZK11US, HZK12US, HZK14US, HZK16US分别是11/12/14/16点阵的汉字库, 每个汉字占用22/24/28/32字节.)

有时只需要显示少数几个汉字, 这时用小字库更方便, 放在MCU的FLASH里就行了.
为此我写了一个小工具, 从需要显示汉字的源程序里筛选出汉字, 去掉重复, 按Unicode顺序排列;
然后从上述几个字库文件里依次找到相应的字模, 再以C语言unsigned char数组的形式保存.
此外还需要一个查找表, 用户程序里读取字模时先根据汉字的Unicode内码找到索引位置, 再从后面的字模数组读取即可.

使用方法: 

py gen_smlib.py test.cc > output.c

其中test.cc包含所有需要显示的汉字, output.c是输出的小字库文件.

显示效果如图, 其中12/14/16点阵字库包含序号/制表符/日文假名, 缺希腊字母和西里尔字母.
11点阵字库则基本只有汉字(假名似乎存储位置有点错位). 以后有机会了找找完全版的补上.

![效果图](output.png)
