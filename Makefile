CC			:= clang-14
CXX			:= clang++-14
LD			:= ld.gold
OPT			:= opt-14
BINDIR		:= bin
LIBDIR		:= lib
BUILDDIR	:= build
DOCDIR		:= docs
CFLAGS		:= -std=gnu++14
LDFLAGS		:= 
DEBUG_FLAGS := -g -O0 -fno-omit-frame-pointer
REL_FLAGS	:= -O3 -fomit-frame-pointer

# pkg-config for external libraries
LLVM_CFLAGS		:= $(shell llvm-config-14 --cflags)
LLVM_LDFLAGS	:= $(shell llvm-config-14 --ldflags) $(shell llvm-config-14 --libs)


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
	$(CXX) $(WARNFLAGS) $(LLVM_CFLAGS) $(DEBUG_FLAGS) -Iinclude/ -o $(BINDIR)/AssemblyWords src/*.cc $(LLVM_LDFLAGS)

# Test
test: AssemblyWords
	$(BINDIR)/AssemblyWords