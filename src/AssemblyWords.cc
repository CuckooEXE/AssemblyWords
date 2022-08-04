#include "AssemblyWords.hh"

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





    MCCodeEmitter *CE;
    MCStreamer *Streamer;
    unsigned char *encoding;
    SmallString<1024> Msg;
    raw_svector_ostream OS(Msg);
    unsigned char* insn = NULL;
    size_t* insn_size = 0;

    SourceMgr SrcMgr;
    MCObjectFileInfo MOFI;
    MCContext Ctx(triple, MAI, MRI, STI, SrcMgr);

    Streamer = target->createMCObjectStreamer(triple, Ctx, MAB, OS, CE, *STI,true, true, true);
    if (!Streamer) {
        std::cerr << "Failed to create the MachineCode Streamer" << std::endl;
        return -1;
    }

    ErrorOr<std::unique_ptr<MemoryBuffer>> BufferPtr = MemoryBuffer::getMemBuffer("jmp eax");
    if (BufferPtr.getError()) {
        std::cerr << "Failed to create the Buffer" << std::endl;
        return -1;
    }

    SrcMgr.clearBuffers();
    SrcMgr.AddNewSourceBuffer(std::move(*BufferPtr), SMLoc());

    MCAsmParser *Parser = createMCAsmParser(SrcMgr, Ctx, *Streamer, *MAI);
    if (!Parser) {
        std::cerr << "Failed to create the MachineCode Assembly Parser" << std::endl;
        return -1;
    }

    TAP->KsSyntax = 
    Parser->setTargetParser(*TAP);




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