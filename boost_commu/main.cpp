
#include <iostream>
#include <string>
using namespace std;

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/mapped_region.hpp>

using namespace boost::interprocess;

#define BUF_SIZE 1025

int main()
{
	//create shared memory object
	shared_memory_object share_obj(create_only, "share1_memory", read_write);

	//set the size of the shared memory
	share_obj.truncate(BUF_SIZE-1);

	//map the shared memory to current process
	mapped_region mmap(share_obj, read_write);

	//access the mapped resion 
	//strcpy(static_cast<char*>(mmap.get_address()), "Hello world!");

	
	while (1)
	{
		cout << "input..." << endl;
		char szInfo[BUF_SIZE] = { 0 };
	
		gets_s(szInfo, 1025);  // 其实gets并不安全
		//strncpy(mmap.get_address(), szInfo, BUF_SIZE - 1);
		std::strncpy((char*)mmap.get_address(), szInfo, BUF_SIZE - 1);
		//share_obj[BUF_SIZE - 1] = '\0';
	}


//	shared_memory_object::remove("shared_memory");
	return 0;

}
