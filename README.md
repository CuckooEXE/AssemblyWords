# AssemblyWords

English words that are encoded ISA instructions interpreted as ASCII.

I was writing some code one day when I ran [GNU Binutil's](https://www.gnu.org/software/binutils/) `strings` program against it. In it, I saw a funny word, `tAble`. I couldn't find it in any of my actual strings until I realized it was in the `.text` section of my program, which means it was raw instructions that just so happened to have an ASCII value of a real English word. 

I mentioned it to my coworker who drew the analogy to the [HexWords](https://nedbatchelder.com/text/hexwords.html) project.

## Generating Instructions

The first problem to tackle is to generate a _complete_ list of valid ISA Instructions. Since x86-64 instructions can take up [15 bytes](https://stackoverflow.com/a/18972014), we don't want to naively generate 2^15 bytes and try to assemble all of them.

Instead, let's see if we can get a complete list of instructions for a particular ISA, and if we can, their valid operands (memory, register, immediate, etc.).

