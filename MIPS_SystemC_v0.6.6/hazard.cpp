
#include "hazard.h"

/**
 * Callback for the hazrd detection of \c hazard module.
 */
void hazard::detect_hazard()
{
	//data hazards
	if(    rs.read()!=0 && rs.read()==WriteReg_exe.read() && RegWrite_exe.read()==true
	    || rs.read()!=0 && rs.read()==WriteReg_mem.read() && RegWrite_mem.read()==true
		|| rs.read()!=0 && rs.read()==WriteReg_id2.read() && RegWrite.read()==true
		|| rt.read()!=0 && rt.read()==WriteReg_id2.read() && RegWrite.read()==true && MemRead.read()==true
	    || rt.read()!=0 && rt.read()==WriteReg_exe.read() && RegWrite_exe.read()==true && MemRead_exe.read()==true //MemRead_exe
	    || rt.read()!=0 && rt.read()==WriteReg_mem.read() && RegWrite_mem.read()==true && MemRead_mem.read()==true ) { // MemRead_mem

		enable_pc.write(false);
		enable_ifid.write(false);
		reset_id1id2.write(true);
		enable_regs.write(false);
		perror("HAZARD");
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
	if (BranchTaken.read()==true){
	    enable_pc.write(true);
		enable_ifid.write(true);
		reset_id1id2.write(true);
		reset_id2exe.write(true);
		reset_exemem.write(true);
		reset_ifid.write(true);
	}
}
