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

/**
 * Callback for the hazrd detection of \c hazard module.
 */
void hazard::detect_hazard()
{
	//data hazards
	if( rs.read()!=0 && rs.read()==WriteReg_exe.read() && RegWrite_exe.read()==true
	    || rs.read()!=0 && rs.read()==WriteReg_mem.read() && RegWrite_mem.read()==true
		//|| rs.read()!=0 && rs.read()==WriteReg_id2.read() && RegWrite.read()==true
		//|| rt.read()!=0 && rt.read()==WriteReg_id2.read() && RegWrite.read()==true
	    || rt.read()!=0 && rt.read()==WriteReg_exe.read() && RegWrite_exe.read()==true && MemRead.read()==false
	    || rt.read()!=0 && rt.read()==WriteReg_mem.read() && RegWrite_mem.read()==true && MemRead.read()==false ) {

		enable_pc.write(false);
		enable_ifid.write(false);
		enable_id1id2.write(false);
		reset_id2exe.write(true);

	}
	if (BranchTaken.read()==true){
	    enable_pc.write(true);
		reset_ifid.write(true);
		enable_ifid.write(true);


	}
	else {
	    enable_pc.write(true);
		enable_ifid.write(true);
		enable_id1id2.write(true);
		enable_id2exe.write(true);
		reset_id1id2.write(false);
		reset_id2exe.write(false);
		reset_ifid.write(false);
		reset_exemem.write(false);
	}
}
