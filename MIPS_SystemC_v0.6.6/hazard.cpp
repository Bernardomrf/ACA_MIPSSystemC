
#include "hazard.h"

/**
 * Callback for the hazrd detection of \c hazard module.
 */
void hazard::detect_hazard()
{
	if(	rs_id2.read() != 0 && rs_id2.read() == WriteReg_exe.read() && RegWrite_exe.read() == true && MemRead_exe.read() == true ||
		rt_id2.read() != 0 && rt_id2.read() == WriteReg_exe.read() && RegWrite_exe.read() == true && MemRead_exe.read() == true && MemRead.read() == false ||

		rs_id2.read() != 0 && rs_id2.read() == WriteReg_exe.read() && RegWrite_exe.read() == true && branch.read() != 0 ||
		rt_id2.read() != 0 && rt_id2.read() == WriteReg_exe.read() && RegWrite_exe.read() == true && branch.read() != 0 && MemRead.read() == false ||

		rs_id2.read() != 0 && rs_id2.read() == WriteReg_mem.read() && RegWrite_mem.read() == true && branch.read() != 0 && MemRead_mem.read() == true ||
		rt_id2.read() != 0 && rt_id2.read() == WriteReg_mem.read() && RegWrite_mem.read() == true && branch.read() != 0 && MemRead.read() == false && MemRead_mem.read() == true
		){
		enable_pc.write(false);
		enable_ifid.write(false);
		enable_id1id2.write(false);
		enable_regs.write(false);
		reset_id2exe.write(true);
	}
	else
	if (BranchTaken.read()==true){
	    enable_pc.write(true);
		enable_ifid.write(true);
		reset_ifid.write(true);

		enable_regs.write(true);
		enable_id1id2.write(true);
		enable_id2exe.write(true);

		reset_id1id2.write(false);
		reset_id2exe.write(false);
		reset_exemem.write(false);
		reset_regs.write(false);
	}
	else {
	    enable_pc.write(true);
		enable_ifid.write(true);
		enable_regs.write(true);
		enable_id1id2.write(true);
		enable_id2exe.write(true);

		reset_id1id2.write(false);
		reset_id2exe.write(false);
		reset_ifid.write(false);
		reset_exemem.write(false);
		reset_regs.write(false);

	}
}
