//
// #include "hazard.h"
//
// /**
//  * Callback for the hazrd detection of \c hazard module.
//  */
// void hazard::detect_hazard()
// {
// 	//data hazards
// 	if(    rs.read()!=0 && rs.read()==WriteReg_exe.read() && RegWrite_exe.read()==true )
// 	{
// 		perror("1");
// 		enable_pc.write(false);
// 		enable_ifid.write(false);
// 		enable_id1id2.write(false);
// 		reset_id2exe.write(true);
//
// 	}
// 	else if ( rs.read()!=0 && rs.read()==WriteReg_mem.read() && RegWrite_mem.read()==true )
// 		// || rs.read()!=0 && rs.read()==WriteReg_id2.read() && RegWrite.read()==true
// 		// || rt.read()!=0 && rt.read()==WriteReg_id2.read() && RegWrite.read()==true && MemRead.read()==false
// 	{
// 		perror("2");
//
// 		enable_pc.write(false);
// 		enable_ifid.write(false);
// 		enable_id1id2.write(false);
// 		reset_id2exe.write(true);
//
//
// 	}
// 	else if ( rt.read()!=0 && rt.read()==WriteReg_exe.read() && RegWrite_exe.read()==true && MemRead.read()==false )
// 	{
// 		perror("3");
//
// 		enable_pc.write(false);
// 		enable_ifid.write(false);
// 		enable_id1id2.write(false);
// 		enable_id2exe.write(false);
// 		reset_exemem.write(true);
//
// 	}
// 	else if ( rt.read()!=0 && rt.read()==WriteReg_mem.read() && RegWrite_mem.read()==true && MemRead.read()==false ) {
// 		perror("4");
//
// 		enable_pc.write(false);
// 		enable_ifid.write(false);
// 		enable_id1id2.write(false);
// 		enable_id2exe.write(false);
// 		reset_exemem.write(true);
//
// 	}
// 	else if (BranchTaken.read()==true){
// 	  enable_pc.write(true);
// 		reset_ifid.write(true);
//
// 	}
// 	else {
// 		perror("ELSE");
// 	    enable_pc.write(true);
// 		enable_ifid.write(true);
// 		enable_id1id2.write(true);
// 		enable_id2exe.write(true);
// 		reset_id2exe.write(false);
// 		reset_ifid.write(false);
// 		reset_exemem.write(false);
// 		reset_id1id2.write(false);
//
//
// 	}
// }

#include "hazard.h"


static int i_hazard = 0;

/**
 * Callback for the hazrd detection of \c hazard module.
 */
void hazard::detect_hazard()
{





	//data hazards
	if(    rs.read()!=0 && rs.read()==WriteReg_exe.read() && RegWrite_exe.read()==true
	    || rs.read()!=0 && rs.read()==WriteReg_mem.read() && RegWrite_mem.read()==true
	    || rt.read()!=0 && rt.read()==WriteReg_exe.read() && RegWrite_exe.read()==true && MemRead.read()==false
	    || rt.read()!=0 && rt.read()==WriteReg_mem.read() && RegWrite_mem.read()==true && MemRead.read()==false ) {

		fprintf(stderr, "if!\n");
		enable_pc.write(false);
		enable_ifid.write(false);
		enable_id1id2.write(false);
		enable_regs.write(false);
		reset_id2exe.write(true);

	}

	else {
		fprintf(stderr, "else!\n");

	    enable_pc.write(true);
		enable_ifid.write(true);
		enable_id1id2.write(true);
		enable_id2exe.write(true);
		enable_regs.write(true);
		reset_id1id2.write(false);
		reset_id2exe.write(false);
		reset_ifid.write(false);
		reset_exemem.write(false);
		reset_regs.write(false);
	}

	if (BranchTaken.read()==true){
	    enable_pc.write(true);
		reset_ifid.write(true);
		enable_ifid.write(true);
	}else{
		reset_ifid.write(false);
	}

	fprintf(stderr, "--- detect_hazard  %d  ----\n", i_hazard++);
	//fprintf(stderr, "\n");

	fprintf(stderr, "# rs: %d\n", (int)rs.read());
	fprintf(stderr, "# rt: %d\n", (int)rt.read());
	fprintf(stderr, "# WriteReg_mem: %d\n", (int)WriteReg_mem.read());
	fprintf(stderr, "# RegWrite_exe: %d\n", (int)RegWrite_exe.read());
	fprintf(stderr, "# MemRead: %d\n", (int)MemRead.read());
	fprintf(stderr, "# WriteReg_id2: %d\n", (int)WriteReg_id2.read());
	fprintf(stderr, "\n");
	fprintf(stderr, "@ enable_pc: %d\n", (int)enable_pc.read());
	fprintf(stderr, "@ enable_ifid: %d\n", (int)enable_ifid.read());
	fprintf(stderr, "@ enable_id1id2: %d\n", (int)enable_id1id2.read());
	fprintf(stderr, "@ enable_id2exe: %d\n", (int)enable_id2exe.read());
	fprintf(stderr, "@ reset_id2exe: %d\n", (int)reset_id2exe.read());
	fprintf(stderr, "@ reset_exmem: %d\n", (int)reset_id2exe.read());
	fprintf(stderr, "@ reset_ifid: %d\n", (int)reset_id2exe.read());
	fprintf(stderr, "@ enable_regs: %d\n", (int)enable_regs.read());
	fprintf(stderr, "* BranchTaken: %d\n", (int)BranchTaken.read());
	fprintf(stderr, "--- fim hazard ----\n");
}
