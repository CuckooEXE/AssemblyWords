#include "AssemblyWords.hh"

using namespace llvm;

int main(int argc, const char* argv[])
{
    std::string err;
    MCInst MI;
    MCTargetOptions MTO;
    Triple* triple = nullptr;
    const Target* target = nullptr;
    const TargetMachine* TM = nullptr;
    const MCInstrInfo* MII = nullptr;
    const MCAsmInfo* MAI = nullptr;
    const MCRegisterInfo* MRI = nullptr;
    const MCSubtargetInfo* MSTI = nullptr;
    MCInstPrinter* MIP = nullptr;

    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    std::cout << "Creating Triple..." << std::endl;
    triple = new Triple(
        Triple::getArchTypeName(Triple::ArchType::x86_64),
        Triple::getVendorTypeName(Triple::VendorType::UnknownVendor),
        Triple::getOSTypeName(Triple::OSType::UnknownOS)
    );
    if (!triple) {
        std::cerr << "Failed to create the Triple" << std::endl;
        return -1;
    }

    std::cout << "Creating Target..." << std::endl;
    target = TargetRegistry::lookupTarget(triple->str(), err);
    if (!target) {
        std::cerr << "TargetRegistry::lookupTarget(" << triple->str() << ") failed with error: " << err << std::endl;
        return -1;
    }

    std::cout << "Creating TargetMachine..." << std::endl;
    TM = target->createTargetMachine(triple->str(), "generic", "", {}, {});
    if (!TM) {
        std::cerr << "target->createTargetMachine(" << triple->str() << ", \"generic\", \"\", {}, {}) failed" << std::endl;
        return -1;
    }

    std::cout << "Creating MCInstrInfo..." << std::endl;
    MII = TM->getMCInstrInfo();
    if (!MII) {
        std::cerr << "target->createMCInstrInfo() failed" << std::endl;
        return -1;
    }

    std::cout << "Creating MCSubtargetInfo..." << std::endl;
    MSTI = target->createMCSubtargetInfo(triple->str(), "", "");
    if (!MSTI) {
        std::cerr << "target->createMCSubtargetInfo(" << triple->str() << ", \"\", \"\") failed" << std::endl;
        return -1;
    }

    std::cout << "Creating MCInstPrinter..." << std::endl;
    MIP = target->createMCInstPrinter(*triple, 0, *MAI, *MII, *MRI);
    if (!MIP) {
        std::cerr << "target->createMCInstPrinter(*triple, 0, *MAI, *MII, *MRI) failed" << std::endl;
        return -1;
    }

    std::cout << "Configuring MCTargetOptions..." << std::endl;
    MTO.AsmVerbose = true;
    MTO.ShowMCEncoding = true;
    MTO.ShowMCInst = true;

    std::cout << "Creating MCRegisterInfo..." << std::endl;
    MRI = target->createMCRegInfo(triple->str());
    if (!MRI) {
        std::cerr << "target->createMCRegInfo(" << triple->str() << ") failed" << std::endl;
        return -1;
    }

    std::cout << "Creating MCAsmInfo..." << std::endl;
    MAI = target->createMCAsmInfo(*MRI, triple->str(), MTO);
    if (!MAI) {
        std::cerr << "target->createMCAsmInfo(*MRI, " << triple->str() << ", MTO) failed" << std::endl;
        return -1;
    }

    std::cout << "Creating MCInst..." << std::endl;

    MI.setOpcode(17671);
    MI.addOperand(MCOperand::createReg(49));
    MI.addOperand(MCOperand::createReg(49));
    MI.addOperand(MCOperand::createReg(49));

    std::cout << "MCInst: " << std::endl;
    MIP->printInst(&MI, 1, "", *MSTI, llvm::outs());
    std::cout << std::endl;

    


    // const TargetInstrInfo &TII = ...
    // MachineBasicBlock &MBB = ...
    // DebugLoc DL;
    // MachineInstr *MI = BuildMI(MBB, DL, TII.get(X86::MOV32ri), DestReg).addImm(42);

    // // Create the same instr, but insert it before a specified iterator point.
    // MachineBasicBlock::iterator MBBI = ...
    // BuildMI(MBB, MBBI, DL, TII.get(X86::MOV32ri), DestReg).addImm(42);

    // // Create a 'cmp Reg, 0' instruction, no destination reg.
    // MI = BuildMI(MBB, DL, TII.get(X86::CMP32ri8)).addReg(Reg).addImm(42);

    // // Create an 'sahf' instruction which takes no operands and stores nothing.
    // MI = BuildMI(MBB, DL, TII.get(X86::SAHF));

    // // Create a self looping branch instruction.
    // BuildMI(MBB, DL, TII.get(X86::JNE)).addMBB(&MBB);

    std::cout << "Done!" << std::endl;

    return 0;
}
