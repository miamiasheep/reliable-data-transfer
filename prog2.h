#ifndef PROG2_H_
#define PROG2_H_
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

/* ******************************************************************
   ALTERNATING BIT AND GO-BACK-N NETWORK EMULATOR: VERSION 1.1  J.F.Kurose

   This code should be used for PA2, unidirectional or bidirectional
   data transfer protocols (from A to B. Bidirectional transfer of data
   is for extra credit and is not required).  Network properties:
   - one way network delay averages five time units (longer if there
   are other messages in the channel for GBN), but can be larger
   - packets can be corrupted (either the header or the data portion)
   or lost, according to user-defined probabilities
   - packets will be delivered in the order in which they were sent
   (although some can be lost).
**********************************************************************/

#define BIDIRECTIONAL 0 /* change to 1 if you're doing extra credit */
                        /* and write a routine called B_output */

/* a "msg" is the data unit passed from layer 5 (teachers code) to layer  */
/* 4 (students' code).  It contains the data (characters) to be delivered */
/* to layer 5 via the students transport level protocol entities.         */
struct msg
{
  char data[20];
};

/* a packet is the data unit passed from layer 4 (students code) to layer */
/* 3 (teachers code).  Note the pre-defined packet structure, which all   */
/* students must follow. */
struct pkt
{
  int seqnum;
  int acknum;
  int checksum;
  char payload[20];
};

int A_output(struct msg);
int A_input(struct pkt);
int A_timerinterrupt();

int B_input(struct pkt);

/*****************************************************************
 ***************** NETWORK EMULATION CODE STARTS BELOW ***********
The code below emulates the layer 3 and below network environment:
  - emulates the tranmission and delivery (possibly with bit-level corruption
    and packet loss) of packets across the layer 3/4 interface
  - handles the starting/stopping of a timer, and generates timer
    interrupts (resulting in calling students timer handler).
  - generates message to be sent (passed from later 5 to 4)

THERE IS NOT REASON THAT ANY STUDENT SHOULD HAVE TO READ OR UNDERSTAND
THE CODE BELOW.  YOU SHOLD NOT TOUCH, OR REFERENCE (in your code) ANY
OF THE DATA STRUCTURES BELOW.  If you're interested in how I designed
the emulator, you're welcome to look at the code - but again, you should have
to, and you defeinitely should not have to modify
******************************************************************/

struct event
{
  float evtime;       /* event time */
  int evtype;         /* event type code */
  int eventity;       /* entity where event occurs */
  struct pkt * pktptr; /* ptr to packet (if any) assoc w/ this event */
  struct event * prev;
  struct event * next;
};

struct event * evlist = NULL; /* the event list */

/* possible events: */
#define TIMER_INTERRUPT 0
#define FROM_LAYER5 1
#define FROM_LAYER3 2

#define OFF 0
#define ON 1
#define A 0
#define B 1

/* globals */
extern int TRACE;   /* for my debugging */
extern int nsim;    /* number of messages from 5 to 4 so far */
extern int nsimmax; /* number of msgs to generate, then stop */
extern float time;
extern float lossprob;    /* probability that a packet is dropped  */
extern float corruptprob; /* probability that one bit is packet is flipped */
extern float lambda;      /* arrival rate of messages from layer 5 */
extern int ntolayer3;     /* number sent into layer 3 */
extern int nlost;         /* number lost in media */
extern int ncorrupt;      /* number corrupted by media*/
unsigned int rand_seed = 9999;

int main();
void init();
float jimsrand();
void generate_next_arrival();
void printevlist();
void stoptimer(int);
void insertevent(struct event *);
void tolayer3(int, struct pkt);
void tolayer5(int, const char *);

#endif  // PROG2_H_
