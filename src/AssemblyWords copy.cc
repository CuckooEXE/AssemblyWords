// #include "AssemblyWords.hh"

// using namespace llvm;

// int main(int argc, const char* argv[])
// {
//     bool is_valid_opcode = false;
//     std::string err;
//     MCInst MI;
//     MCTargetOptions MTO;
//     MCInstrDesc MCID;
//     SmallVector<MCFixup, 0> Fixups;
//     MCContext* Ctx = nullptr;
//     Triple* triple = nullptr;
//     const MCCodeEmitter* MCE = nullptr;
//     const Target* target = nullptr;
//     const TargetMachine* TM = nullptr;
//     const MCInstrInfo* MII = nullptr;
//     const MCAsmInfo* MAI = nullptr;
//     const MCRegisterInfo* MRI = nullptr;
//     const MCSubtargetInfo* MSTI = nullptr;
//     MCInstPrinter* MIP = nullptr;    
    
//     json::OStream J(llvm::outs());
//     J.objectBegin();
//     J.attribute("test", 5);
//     J.attributeArray("participants", [&] {
//         J.value(5);
//         J.value(6);
//         J.attribute("test", 7);
//     });
//     J.objectEnd();
    
//     InitializeAllTargetInfos();
//     InitializeAllTargets();
//     InitializeAllTargetMCs();
//     InitializeAllAsmParsers();
//     InitializeAllAsmPrinters();

//     std::cout << "Creating Triple..." << std::endl;
//     triple = new Triple(
//         Triple::getArchTypeName(Triple::ArchType::x86_64),
//         Triple::getVendorTypeName(Triple::VendorType::UnknownVendor),
//         Triple::getOSTypeName(Triple::OSType::UnknownOS)
//     );
//     if (!triple) {
//         std::cerr << "Failed to create the Triple" << std::endl;
//         return -1;
//     }

//     std::cout << "Creating Target..." << std::endl;
//     target = TargetRegistry::lookupTarget(triple->str(), err);
//     if (!target) {
//         std::cerr << "TargetRegistry::lookupTarget(" << triple->str() << ") failed with error: " << err << std::endl;
//         return -1;
//     }

//     std::cout << "Creating TargetMachine..." << std::endl;
//     TM = target->createTargetMachine(triple->str(), "generic", "", {}, {});
//     if (!TM) {
//         std::cerr << "target->createTargetMachine(" << triple->str() << ", \"generic\", \"\", {}, {}) failed" << std::endl;
//         return -1;
//     }

//     std::cout << "Creating MCInstrInfo..." << std::endl;
//     MII = TM->getMCInstrInfo();
//     if (!MII) {
//         std::cerr << "target->createMCInstrInfo() failed" << std::endl;
//         return -1;
//     }

//     std::cout << "Creating MCSubtargetInfo..." << std::endl;
//     MSTI = target->createMCSubtargetInfo(triple->str(), "", "");
//     if (!MSTI) {
//         std::cerr << "target->createMCSubtargetInfo(" << triple->str() << ", \"\", \"\") failed" << std::endl;
//         return -1;
//     }

//     std::cout << "Creating MCInstPrinter..." << std::endl;
//     MIP = target->createMCInstPrinter(*triple, 0, *MAI, *MII, *MRI);
//     if (!MIP) {
//         std::cerr << "target->createMCInstPrinter(*triple, 0, *MAI, *MII, *MRI) failed" << std::endl;
//         return -1;
//     }

//     std::cout << "Configuring MCTargetOptions..." << std::endl;
//     MTO.AsmVerbose = true;
//     MTO.ShowMCEncoding = true;
//     MTO.ShowMCInst = true;

//     std::cout << "Creating MCRegisterInfo..." << std::endl;
//     MRI = target->createMCRegInfo(triple->str());
//     if (!MRI) {
//         std::cerr << "target->createMCRegInfo(" << triple->str() << ") failed" << std::endl;
//         return -1;
//     }

//     std::cout << "Creating MCAsmInfo..." << std::endl;
//     MAI = target->createMCAsmInfo(*MRI, triple->str(), MTO);
//     if (!MAI) {
//         std::cerr << "target->createMCAsmInfo(*MRI, " << triple->str() << ", MTO) failed" << std::endl;
//         return -1;
//     }

//     std::cout << "Creating MCContext..." << std::endl;
//     Ctx = new MCContext(*triple, MAI, MRI, MSTI);
//     if (!Ctx) {
//         std::cerr << "Failed to create the MCContext" << std::endl;
//         return -1;
//     }

//     std::cout << "Creating MCCodeEmitter..." << std::endl;
//     MCE = target->createMCCodeEmitter(*MII, *Ctx);
//     if (!MCE) {
//         std::cerr << "target->createMCCodeEmitter(*MII, *MRI, *MSTI, *TM, MTO) failed" << std::endl;
//         return -1;
//     }

//     std::cout << "Iterating over Opcodes..." << std::endl;
//     for (size_t i = 0; i < 35; i++) {
//         MCID = MII->get(i);
//         std::cout << MII->getName(i).str() << ": " << i << std::endl;
//         is_valid_opcode = MCID.getNumOperands() == 0; // Assume it's valid if it has no operands

//         // Check all operands, we only operate on instructions with all register operands
//         // for (const MCOperandInfo& op : MCID.operands()) {
//         //     if (op.OperandType == MCOI::OperandType::OPERAND_REGISTER) {
//         //         is_valid_opcode = true;
//         //     }
//         //     else {
//         //         is_valid_opcode = false;
//         //     }
//         // }
//         // if (!is_valid_opcode) {
//         //     continue;
//         // }
//         MI.setOpcode(i);

//         // Outputs as binary
//         // MCE->encodeInstruction(MI, llvm::errs(), Fixups, *MSTI); std::cout << std::endl;
//     }

//     std::cout << "Done!" << std::endl;
//     return 0;
// }
