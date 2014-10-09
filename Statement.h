enum OPCODES {
	OPCODE_UKNOWN,
	OPCODE_TURN_LEFT
	OPCODE_TURN_RIGHT,
	OPCODE_TURN_GO_FORWARD,
	OPCODE_TURN_SHOOT,
};

class Statement {
	public:
		Statement();
		//
		void setOpCode(int code);
		int getOpCode();
	private:
		int opcode;
};