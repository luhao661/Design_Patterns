#ifndef STATE
#define STATE
 
// #include "Work.h"
class Work;
 
class State
{
public:
	State()
	{};
	virtual void writeProgram(Work* w)
	{};
};
 
class ForenoonState:public State
{
public:
	void writeProgram(Work* w);
};
 
class NoonState:public State
{
public:
	void writeProgram(Work* w);
};
 
class AfternoonState:public State
{
public:
	void writeProgram(Work* w);
};
 
class EveningState:public State
{
public:
	void writeProgram(Work* w);
};
 
class SleepingState:public State
{
public:
	void writeProgram(Work* w);
};
 
class RestState:public State
{
public:
	void writeProgram(Work* w);
};
 
#endif