#include "IFS_SD.h"
#include "SD.h"

namespace IcarusLib{

	//	constructor
	IFS_SD::IFS_SD()
	{
		//sd = new SD;

	}
	
	IFS_SD::~IFS_SD()
	{
		//destroyes the pointer
		//delete sd;

	}

	unsigned IFS_SD::InitializeSD(unsigned cspin)
	{
		if(!SD.begin(cspin))
		{
			//indicates that card failed
			return 0; 
		}	
			//everything ok
			sdtype=cspin;
			return 1;
	}

		//ver se precisa retornar algo e a questão de vector para files
	  unsigned IFS_SD::OpenfileSD (File &namefile,const string path,  string preference) 
	  {
	  		//it opens the file on SD card. Preference is or FILE_WRITE or FILE_READ
	  		nameFile= SD.open(path, preference);
	  			
	  			if(nameFile){
	  				return 1; //if everything is ok, returns 1
	  			}

	  			return 0; //if there's something wrong

	  }

	  void IFS_SD::ClosefileSD(File &namefile)
	  {
	  		namefile.close();
	  }

	  void IFS_SD::PrintlnfileSD (File &namefile, <template> data, string BASE)
	  {
	  		namefile.println(data, BASE);

	  }	  

	  void IFS_SD::PrintfileSD (File &namefile, <template> data, string BASE)
	  {
	  		namefile.print(data, BASE);

	  }	  




}