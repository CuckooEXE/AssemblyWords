#include "AssemblyWords.hh"


#include "X86FrameLowering.h"
#include "X86InstrBuilder.h"
#include "X86InstrInfo.h"
#include "X86MachineFunctionInfo.h"
#include "X86Subtarget.h"


using namespace llvm;

int main(int argc, const char* argv[])
{
    std::string err;
    MCTargetOptions MCOptions = mc::InitMCTargetOptionsFromFlags();
    Triple* triple = nullptr;
    const Target* target = nullptr;
    MCRegisterInfo* MRI = nullptr;
    MCInstrInfo* MCII = nullptr;
    MCSubtargetInfo* STI = nullptr;
    MCAsmBackend* MAB = nullptr;
    MCAsmInfo* MAI = nullptr;

    const TargetInstrInfo &TTI = llvm::TargetInstrInfo();
    TTI.get()

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


    // Iterate over all the ArchTypes
    // for(int arch = Triple::ArchType::UnknownArch; arch < Triple::ArchType::LastArchType; arch++) {
    //     Triple trip(
    //         Triple::getArchTypeName(static_cast<llvm::Triple::ArchType>(arch)),
    //         Triple::getVendorTypeName(Triple::VendorType::UnknownVendor),
    //         Triple::getOSTypeName(Triple::OSType::UnknownOS)
    //     );
    //     std::cout << "Operating over " << trip.str() << std::endl;

    //     break;
    // }

    // Initialize Targets, MachineCodes, and Parsers
    InitializeAllTargetInfos();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    
    // Create the Triple
    triple = new Triple(
        Triple::getArchTypeName(Triple::ArchType::x86_64),
        Triple::getVendorTypeName(Triple::VendorType::UnknownVendor),
        Triple::getOSTypeName(Triple::OSType::UnknownOS)
    );
    if (!triple) {
        std::cerr << "Failed to create the Triple" << std::endl;
        return -1;
    }

    // Create a Target based on the Triple
    target = TargetRegistry::lookupTarget(triple->str(), err);
    if (!target) {
        std::cerr << "TargetRegistry::lookupTarget(" << triple->str() << ") failed with error: " << err << std::endl;
        return -1;
    }

    // Get the MachineCode Register Info from the Target
    MRI = target->createMCRegInfo(triple->str());
    if (!MRI) {
        std::cerr << "Failed to create the MachineCode Register Info" << std::endl;
        return -1;
    }

    // Create the MachineCode Assembly Info
    MAI = target->createMCAsmInfo(*MRI, triple->str(), MCOptions);
    if (!MAI) {
        std::cerr << "Failed to create the MachineCode Assembly Info" << std::endl;
        return -1;
    }

    // Create the MachineCode Instruction Info
    MCII = target->createMCInstrInfo();
    if (!MCII) {
        std::cerr << "Failed to create the MachineCode Instruction Info" << std::endl;
        return -1;
    }

    // Create the MachineCode Subtarget Info
    STI = target->createMCSubtargetInfo(triple->str(), "", "");
    if (!STI) {
        std::cerr << "Failed to create the MachineCode Subtarget Info" << std::endl;
        return -1;
    }

    // Create the MachineCode Assembly Backend
    MAB = target->createMCAsmBackend(*STI, *MRI, MCOptions);
    if (!MAB) {
        std::cerr << "Failed to create the MachineCode Assembly Backend" << std::endl;
        return -1;
    }
    std::cout << "Done!" << std::endl;

    return 0;
}


/*
static StringRef 	getArchTypeName (ArchType Kind)
 	Get the canonical name for the Kind architecture. More...
 
static StringRef 	getArchTypePrefix (ArchType Kind)
 	Get the "prefix" canonical name for the Kind architecture. More...
 
static StringRef 	getVendorTypeName (VendorType Kind)
 	Get the canonical name for the Kind vendor. More...
 
static StringRef 	getOSTypeName (OSType Kind)
 	Get the canonical name for the Kind operating system. More...
 
static StringRef 	getEnvironmentTypeName (EnvironmentType Kind)
*/