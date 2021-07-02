#include <iostream>
#include <string>

using namespace std;

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/mapped_region.hpp>

using namespace boost::interprocess;

#define BUF_SIZE 1025

int main()
{
	//open shared memory object
	//shared_memory_object share_obj(open_only, "shared_memory", read_only);
	shared_memory_object share_obj(open_only, "share1_memory", read_only);

	//map the shared memory object to current process
	//mapped_region mmap(share_obj, read_only);
	mapped_region mmap(share_obj, read_only);

	while (1)
	{
		cout << "press any button to receive data..." << endl;
		getchar();
		cout << static_cast<char*>(mmap.get_address()) << endl;
		shared_memory_object::remove("share1_memory");
	}


	//remove shared memory object

	return 0;
}