LLVM_VER	:= 14
CC			:= clang-$(LLVM_VER)
CXX			:= clang++-$(LLVM_VER)
OPT			:= opt-$(LLVM_VER)
BINDIR		:= bin
LIBDIR		:= lib
BUILDDIR	:= build
DOCDIR		:= docs
CFLAGS		:= -std=gnu++14
LDFLAGS		:= 
DEBUG_FLAGS := -g -O0 -fno-omit-frame-pointer
REL_FLAGS	:= -O3 -fomit-frame-pointer

# pkg-config for external libraries
LLVM_CFLAGS		:= $(shell llvm-config-$(LLVM_VER) --cflags)
LLVM_LDFLAGS	:= $(shell llvm-config-$(LLVM_VER) --ldflags) $(shell llvm-config-$(LLVM_VER) --libs) -l:libLLVMTableGen.a


DEFAULT: AssemblyWords
.PHONY: clean

# Clean up build artifacts
clean:
	rm -rf $(BINDIR)/
	rm -rf $(LIBDIR)/
	rm -rf $(BUILDDIR)/

# Build all of AssemblyWords
AssemblyWords: $(BINDIR)/AssemblyWords
$(BINDIR)/AssemblyWords:
	mkdir -p $(BINDIR)/
	$(CXX) $(WARNFLAGS) $(LLVM_CFLAGS) -Iinclude/ -o $(BINDIR)/AssemblyWords src/*.cc $(LLVM_LDFLAGS) 

# Test
test: AssemblyWords
	$(BINDIR)/AssemblyWords