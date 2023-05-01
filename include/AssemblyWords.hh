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
#include <string>

#include <llvm/CodeGen/MachineInstrBuilder.h>
#include <llvm/CodeGen/MachineInstr.h>
#include <llvm/CodeGen/TargetInstrInfo.h>
#include <llvm/CodeGen/MachineFunction.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/ADT/Triple.h>
#include <llvm/ADT/SmallVector.h>
#include <llvm/IR/DebugLoc.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/MC/TargetRegistry.h>
#include <llvm/MC/MCContext.h>
#include <llvm/MC/MCInst.h>
#include <llvm/MC/MCAsmInfo.h>
#include <llvm/MC/MCInstPrinter.h>
#include <llvm/MC/MCCodeEmitter.h>
#include <llvm/MC/MCTargetOptions.h>

#endif // !ASSEMBLYWORDS_H_