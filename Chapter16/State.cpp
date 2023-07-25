#include <iostream>
#include "State.h"
#include "Work.h"
 
using namespace std;
 
void ForenoonState::writeProgram(Work* w)
{
	if(w->getHour()<12)
	{
		cout<<"current time"<<w->getHour()<<" "<<"Work in the morning, full of energy"<<endl;
	}
	else
	{
		w->setState(new NoonState);
		w->writeProgram();
	}
}
 
void NoonState::writeProgram(Work* w)
{
	if(w->getHour()<13)
	{
		cout<<"current time" <<w->getHour()<<" "<<"Hungry, lunch; Sleepy, noon break"<<endl;
	}
	else
	{
		w->setState(new AfternoonState);
		w->writeProgram();
	}
}
 
void AfternoonState::writeProgram(Work* w)
{
	if(w->getHour()<17)
		cout<<"current time" <<w->getHour()<<" "<<"It was good this afternoon. Keep up the good work"<<endl;
	else
	{
		w->setState(new EveningState);
		w->writeProgram();
	}
}
 
void EveningState::writeProgram(Work* w)
{
	if(w->getFinish())
	{
		w->setState(new RestState);
		w->writeProgram();
	}
	else
	{
		if(w->getHour()<21)
			cout<<"current time"<<w->getHour()<<" "<<"Working overtime. I'm exhausted"<<endl;
		else
		{
			w->setState(new SleepingState);
			w->writeProgram();
		}
	}
}
 
void SleepingState::writeProgram(Work* w)
{
	cout<<"current time"<<w->getHour()<<" "<<"Fell asleep"<<endl;
}
 
void RestState::writeProgram(Work* w)
{
	cout<<"current time"<<w->getHour()<<" "<<"Went home from work"<<endl;
}