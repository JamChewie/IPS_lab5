#include "start_program.h"		// последовательная версия программы
#include "task2.h"				// параллельная версия
#include "task3.h"				// atomic версия
#include "task4.h"				// crtitical версия
#include "task5.h"				// версия с замками
#include "task5_modified.h"		// финальная версия с максимальной производительностью
int main()
{
	//START_PROGRAM::run();
	//TASK2::run();
	//TASK3::run();
	//TASK4::run();
	//TASK5::run();
	TASK5_M::run();
	return 0;
}