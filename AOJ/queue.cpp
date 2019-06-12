// ALDS 1_3_B: Queue
#include <iostream>
#include <string>
#define len 100000
using namespace std;

struct process{
  string name;
  int time;
};

int n, qms, head, tail;
process p[len];

bool isEmpty(){return head == tail;}

bool isFull(){return head == (tail + 1) % len;}

void enqueue(process x, int qms){
  if(isFull()){
    cout << "Error" << endl;
    return;
  }
  x.time -= qms;
  p[tail] = x;
  if(tail+1 == len){
    tail = 0;
  }else{
    tail++;
  }
}

process dequeue(){
  process x = p[head];
  if(head+1 == len){
    head = 0;
  }else{
    head++;
  }
  return x;
}

int main(void){
  cin >> n;
  cin >> qms;

  for(int i=0; i<n; i++){
    cin >> p[i].name >> p[i].time;
  }

  int total_time = 0;
  head = 0;
  tail = n;
  process x;
  int i = 0;
  while(true){
    if(isEmpty()){break;}
    x = dequeue();
    if(x.time <= qms){
      total_time += x.time;
      cout << x.name << " " << total_time << endl;
    }else{
      total_time += qms;
      enqueue(x, qms);
    }
    i++;
  }
  return 0;
}
