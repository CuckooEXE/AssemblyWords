/**
 * @file AssemblyWords.hh
 * @author Axel Persinger (axel@nullptrsec.io)
 * @brief 
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ASSEMBLYWORDS_H_
#define ASSEMBLYWORDS_H_

#include <iostream>

#include "llvm/ADT/Triple.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCTargetOptionsCommandFlags.h"
#include "llvm/MC/MCTargetOptions.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCParser/MCAsmParser.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/SourceMgr.h"

#include "llvm/CodeGen/TargetInstrInfo.h"
#include "llvm/Support/X86DisassemblerDecoderCommon.h"
#include "llvm/Support/X86TargetParser.h"

#endif // !ASSEMBLYWORDS_H_