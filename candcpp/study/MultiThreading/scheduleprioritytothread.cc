#include<iostream>
using namespace std;

/*************************************************************************
struct sched_param 
{
 int sched_priority;     //Scheduling priority 
};
************************************************************************/

int main()
{
	struct sched_param x;
#if 0
        cout<<"Thread Priority is: "<<x.sched_priority<<endl; //Default Schedule Prority is SCHED_OTHER
	x.sched_priority =sched_get_priority_max(SCHED_FIFO);
        cout<<"Thread Priority is: "<<x.sched_priority<<endl;
	x.sched_priority =sched_get_priority_max(SCHED_RR);
        cout<<"Thread Priority is: "<<x.sched_priority<<endl;
	x.sched_priority =sched_get_priority_max(SCHED_OTHER);
        cout<<"Thread Priority is: "<<x.sched_priority<<endl;
#endif
	x.sched_priority =sched_get_priority_max(SCHED_FIFO);
	//x.sched_priority =sched_get_priority_min(SCHED_FIFO);

	pthread_t t1 = pthread_self();
	int ret = pthread_setschedparam(pthread_self(),SCHED_FIFO,&x);
	if(ret != 0)
	{
		cout<<"Failed in setting sched priority parameters to thread\n";
	}

	int policy=0;
	ret = pthread_getschedparam(pthread_self(),&policy,&x);
	if(ret != 0)
	{
		cout<<"Failed in getting sched priority parameters of thread\n";
	}
	cout<<"Thread Priority is: "<<x.sched_priority<<endl;

}
