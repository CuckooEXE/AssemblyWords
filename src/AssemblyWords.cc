#include <llvm/TableGen/Main.h>
#include <llvm/TableGen/Record.h>
#include <llvm/TableGen/TableGenBackend.h>
#include <llvm/Support/raw_ostream.h>
#include <iostream>

using namespace llvm;

bool EmitX86Opcodes(raw_ostream &OS, RecordKeeper &Records) {
    std::vector<Record*> Recs = Records.getAllDerivedDefinitions("Instruction");
    for (unsigned i = 0, e = Recs.size(); i != e; ++i)
        OS << Recs[i]->getName() << ", ";
    OS << "\n";

}

int main(int argc, char **argv) {
    return TableGenMain(argv[0], &EmitX86Opcodes);
}
