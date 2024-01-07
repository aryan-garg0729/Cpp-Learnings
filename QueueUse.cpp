#include <iostream>
using namespace std;
#include "Queue_Implementation.h"

int main() {
	// {QueueUsingArray<int> q(5);
	// q.enqueue(10);
	// q.enqueue(20);
	// q.enqueue(30);
	// q.enqueue(40);
	// q.enqueue(50);
	// q.enqueue(60);


	// cout << "front: "<<q.front() << endl;
	// cout << "dequeued element:"<<q.dequeue() << endl;
	// cout << "dequeued element:"<<q.dequeue() << endl;
	// cout << "dequeued element:"<<q.dequeue() << endl;

	// cout << "size: "<<q.getSize() << endl;
	// cout << "is empty: "<<q.isEmpty() << endl;}
//----------------------------------------------------------------
	// {QueueLL<int> q;
	// q.enqueue(10);
	// q.enqueue(20);
	// q.enqueue(30);
	// q.enqueue(40);
	// q.enqueue(50);
	// q.enqueue(60);


	// cout << "front: "<<q.front() << endl;
	// cout << "dequeued element:"<<q.dequeue() << endl;
	// cout << "dequeued element:"<<q.dequeue() << endl;
	// cout << "dequeued element:"<<q.dequeue() << endl;

	// cout << "size: "<<q.getSize() << endl;
	// cout << "is empty: "<<q.isEmpty() << endl;}


//------------------------------------------------------------------------------------

	// {DynamicQueue<int> q1(5);
	// q1.enqueue(10);
	// q1.enqueue(20);
	// q1.enqueue(30);
	// q1.enqueue(40);
	// q1.enqueue(50);
	// q1.enqueue(60);


	// cout << q1.front() << endl;
	// cout << q1.dequeue() << endl;
	// cout << q1.dequeue() << endl;
	// cout << q1.dequeue() << endl;

	// cout << q1.getSize() << endl;
	// cout << q1.isEmpty() << endl;}


	{DEQueueLL<int> dq;
	dq.enqueueF(1);
	dq.enqueueF(2);
	dq.enqueueF(3);
	dq.enqueueE(6);
	dq.enqueueE(5);
	cout<<"front: "<<dq.front()<<endl;
	cout<<"rear: "<<dq.rear()<<endl;
	cout<<"front dequeued element: "<<dq.dequeueF()<<endl;
	cout<<"front dequeued element: "<<dq.dequeueF()<<endl;
	cout<<"front dequeued element: "<<dq.dequeueF()<<endl;
	cout<<"rear dequeued element: "<<dq.dequeueE()<<endl;
	cout<<"rear dequeued element: "<<dq.dequeueE()<<endl;
	cout<<"size: "<<dq.getSize()<<endl;
	cout<<"is Empty: "<<dq.isEmpty()<<endl;}



}

