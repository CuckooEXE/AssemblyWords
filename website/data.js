const instructions = [
    {
        architecture: "X86-64",
        instruction: "JMP RAX",
        ascii: "\xFF\xE0",
        hex: "FF E0"
    },
    {
        architecture: "X86-64",
        instruction: "RET",
        ascii: "\xC3",
        hex: "C3"
    },
    {
        architecture: "X86-64",
        instruction: "XOR RAX, RAX",
        ascii: "\x48\x31\xC0",
        hex: "48 31 C0"
    },
    {
		architecture: "avr-unknown-unknown",
		instruction: "BREAK",
		ascii: "b'\x98\x95'",
		hex: "9895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "EICALL",
		ascii: "b'\x19\x95'",
		hex: "1995"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "EIJMP",
		ascii: "b'\x19\x94'",
		hex: "1994"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "ELPM",
		ascii: "b'\xd8\x95'",
		hex: "d895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "ICALL",
		ascii: "b'\t\x95'",
		hex: "0995"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "IJMP",
		ascii: "b'\t\x94'",
		hex: "0994"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "LPM",
		ascii: "b'\xc8\x95'",
		hex: "c895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "NOP",
		ascii: "b'\x00\x00'",
		hex: "0000"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "RET",
		ascii: "b'\x08\x95'",
		hex: "0895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "RETI",
		ascii: "b'\x18\x95'",
		hex: "1895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "SLEEP",
		ascii: "b'\x88\x95'",
		hex: "8895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "SPM",
		ascii: "b'\xe8\x95'",
		hex: "e895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "WDR",
		ascii: "b'\xa8\x95'",
		hex: "a895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "BREAK",
		ascii: "9895",
		hex: "9895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "EICALL",
		ascii: "1995",
		hex: "1995"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "EIJMP",
		ascii: "1994",
		hex: "1994"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "ELPM",
		ascii: "d895",
		hex: "d895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "ICALL",
		ascii: "0995",
		hex: "0995"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "IJMP",
		ascii: "0994",
		hex: "0994"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "LPM",
		ascii: "c895",
		hex: "c895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "NOP",
		ascii: "0000",
		hex: "0000"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "RET",
		ascii: "0895",
		hex: "0895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "RETI",
		ascii: "1895",
		hex: "1895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "SLEEP",
		ascii: "8895",
		hex: "8895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "SPM",
		ascii: "e895",
		hex: "e895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "WDR",
		ascii: "a895",
		hex: "a895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "BREAK",
		ascii: "98 95",
		hex: "9895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "EICALL",
		ascii: "19 95",
		hex: "1995"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "EIJMP",
		ascii: "19 94",
		hex: "1994"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "ELPM",
		ascii: "D8 95",
		hex: "d895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "ICALL",
		ascii: "09 95",
		hex: "0995"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "IJMP",
		ascii: "09 94",
		hex: "0994"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "LPM",
		ascii: "C8 95",
		hex: "c895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "NOP",
		ascii: "00 00",
		hex: "0000"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "RET",
		ascii: "08 95",
		hex: "0895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "RETI",
		ascii: "18 95",
		hex: "1895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "SLEEP",
		ascii: "88 95",
		hex: "8895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "SPM",
		ascii: "E8 95",
		hex: "e895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "WDR",
		ascii: "A8 95",
		hex: "a895"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "BREAK",
		ascii: "\x98\x95",
		hex: "98 95"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "EICALL",
		ascii: "\x19\x95",
		hex: "19 95"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "EIJMP",
		ascii: "\x19\x94",
		hex: "19 94"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "ELPM",
		ascii: "\xD8\x95",
		hex: "D8 95"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "ICALL",
		ascii: "\x09\x95",
		hex: "09 95"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "IJMP",
		ascii: "\x09\x94",
		hex: "09 94"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "LPM",
		ascii: "\xC8\x95",
		hex: "C8 95"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "NOP",
		ascii: "\x00\x00",
		hex: "00 00"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "RET",
		ascii: "\x08\x95",
		hex: "08 95"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "RETI",
		ascii: "\x18\x95",
		hex: "18 95"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "SLEEP",
		ascii: "\x88\x95",
		hex: "88 95"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "SPM",
		ascii: "\xE8\x95",
		hex: "E8 95"
	},	{
		architecture: "avr-unknown-unknown",
		instruction: "WDR",
		ascii: "\xA8\x95",
		hex: "A8 95"
	}
];
