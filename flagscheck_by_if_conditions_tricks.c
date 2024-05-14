//#include <stdint.h>
#include "someLibs/type_def.h"
#include <string.h> //only for memset()
#include <stdio.h>
#include <Windows.h>

typedef enum {
	STATE_ENABLE = 1 << 0,
	STATE_IN_TRANSFERING = 1 << 1,
	STATE_BUSY = 1 << 2,
	STATE_SENDING = 1 << 3,
	//...
	some_flags_lastBit = STATE_SENDING
}some_flags_e;

typedef struct {
	some_flags_e state;
}somePort_t;

#define ONLY
static void checkPortsStates(somePort_t* Port);

int main(char argc, char** argv)
{
	somePort_t Port;
	memset(&Port, 0, sizeof(Port));
	u32 checkValForStyle1 = 0, checkValForStyle2 = 0;

	while (1)
	{
		Sleep(1000);
		if (Port.state & (some_flags_lastBit << 1))
			Port.state = 0;
		Port.state++;

		//I saw the checking flags by if condition this type:
		if (Port.state & STATE_ENABLE) {
			if (((Port.state & STATE_IN_TRANSFERING) == 0) &&
				((Port.state & STATE_BUSY) == 0) &&
				((Port.state & STATE_SENDING) == 0)) {
				printf("Do BIG DEALS 1!\n");
				checkValForStyle1 += 3;
			}//But if there no another condition! <- NOTE.1
		}else{
			//checkValForStyle1++;
		}

		//But what if we write checking flags conditions this type which does the same on above:
		if ((Port.state & (STATE_ENABLE | STATE_IN_TRANSFERING | STATE_BUSY | STATE_SENDING)) == ONLY STATE_ENABLE) {
			printf("Do BIG DEALS 2!\n");
			checkValForStyle2 += 3;
		}//compact & butyied but look at NOTE.1 on above!
		else{
			//checkValForStyle2++;
		}

		checkPortsStates(&Port);
		if (checkValForStyle1 != checkValForStyle2)
			printf("\nOops, there are smthing wrong on style-2 approach! OK, don't beleive me :(, waaaaai bala! Look at Greek facepalm!\n"); //should never get here!
	}
	return -1;
}

static void checkPortsStates(somePort_t* Port)
{
	printf("Ports state: %d %d %d %d\n", ((Port->state & STATE_IN_TRANSFERING) > 0), ((Port->state & STATE_BUSY) > 0), ((Port->state & STATE_SENDING) > 0), ((Port->state & STATE_ENABLE) > 0));
}