

#include<stdio.h>

#include<stdlib.h>



	int Querieshandle();

	int main()

	{

	while(1)

	{

		int details;

	printf("\nEnter your occupation :  \n1 for Faculty  \t2 for Student \n");

	scanf(" %d ",&details);

	switch(details)

	   {

		case 1:

			printf(" \n\tQueries of Faculty : ");

			Querieshandle();

			break;

		case 2:

			printf("\n\tQueries of Students");

			Querieshandle();

			break;

		case 3:

			printf(" \nProgram is terminated ");

			exit(0);

			break;

		default:

			printf("\nInvalid option");

			break;

		}

	}

	}

	int Querieshandle(){

		int a,b,n,t,rem,flag=0,timeQuanta,details;

		 int wait_Time=0,turnaround_Time=0;

		int art[100],but[100],rt[100];

		printf("\nEnter the total number of requests:\t ");

		scanf("%d",&n);

		while(n<=0){

			printf("Request cannot be less than 1 \nEnter again");

			scanf("%d",&n);

	}

		rem=n;

		for(a=0;a<n;a++)

		{

			printf("\nThe Request Number %d :",a+1);

		printf("\nEnter Request's Arrival Time and Burst Time");

		scanf("%d",&art[a]);

		scanf("%d",&but[a]);

		rt[a]=but[a];

		}

		printf("\nHow much time does each request take ? :\t");

		scanf("%d",&timeQuanta);

		while(timeQuanta<=0)

		  {

			printf("Time Quanta can not be less than 1 \nTry again\n Please Enter Again");

			scanf("%d",&timeQuanta);

		}

		printf("\n\nRequest\t      Turnaround Time      Waiting Time\n\n");

		for(t=0,a=0;rem!=0;)

		{

		if(rt[a]<=timeQuanta && rt[a]>0)

		{

		t+=rt[a];

		rt[a]=0;

		flag=1;

		}

		else if(rt[a]>0)

		{

		rt[a]-=timeQuanta;

		t+=timeQuanta;

		}

		if(rt[a]==0 && flag==1)

		{

		rem--;

		printf("P[%d]\t|\t%d\t|\t%d\n",a+1,t-art[a],t-art[a]-but[a]);

		wait_Time+=t-art[a]-but[a];

		turnaround_Time+=t-art[a];

		flag=0;

		}

		if(a==n-1)

		a=0;

		else if(art[a+1]<=t)

		a++;

		else

		a=0;

		}

		printf("\nAverage Waiting Time is= %f\n",wait_Time*1.0/n);

		printf("Avg Turnaround Time is = %f",turnaround_Time*1.0/n);

                return 0;

	}
