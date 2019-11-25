#include <iostream>
#include <queue>
#include <chrono>
#include <cassert>
using namespace std;

enum AnimalKind{ DOG, CAT };

struct AnimalData{
    string name;
    AnimalKind kind;
};

class AnimalShelter{
public:
    void enqueue(AnimalData animal);
    AnimalData dequeueAny();
    AnimalData dequeueCat();
    AnimalData dequeueDog();

private:
    queue<pair<string, chrono::system_clock::time_point>> catQueue;
    queue<pair<string, chrono::system_clock::time_point>> dogQueue;
};

void AnimalShelter::enqueue(AnimalData animal){
    auto now = std::chrono::system_clock::now();
    if(animal.kind == AnimalKind::CAT){
        catQueue.push(make_pair(animal.name, now));
    }else{
        dogQueue.push(make_pair(animal.name, now));
    }
}

AnimalData AnimalShelter::dequeueAny(){
    if(catQueue.empty() && dogQueue.empty()){
        AnimalData animal;
        return animal;
    }

    if(dogQueue.empty()){
        return dequeueCat();
    }
    if(catQueue.empty()){
        return dequeueDog();
    }
    if(catQueue.front().second < dogQueue.front().second){
        return dequeueCat();
    }
    return dequeueDog();
}

AnimalData AnimalShelter::dequeueCat(){
    AnimalData animal;
    if(!catQueue.empty()){
        animal.kind = AnimalKind::CAT;
        animal.name = catQueue.front().first;
        catQueue.pop();
    }
    return animal;
}

AnimalData AnimalShelter::dequeueDog(){
    AnimalData animal;
    if(!dogQueue.empty()){
        animal.kind = AnimalKind::DOG;
        animal.name = dogQueue.front().first;
        dogQueue.pop();
    }
    return animal;
}

int main(void){
    AnimalData cat1 = {"tama", AnimalKind::CAT};
    AnimalData cat2 = {"mike", AnimalKind::CAT};
    AnimalData dog1 = {"pochi", AnimalKind::DOG};
    AnimalData dog2 = {"shiro", AnimalKind::DOG};
    AnimalShelter animalShelter;
    animalShelter.enqueue(cat1);
    animalShelter.enqueue(cat2);
    animalShelter.enqueue(dog1);
    animalShelter.enqueue(dog2);
    AnimalData output1 = animalShelter.dequeueAny(); // cat1
    AnimalData output2 = animalShelter.dequeueDog(); // dog1
    AnimalData output3 = animalShelter.dequeueAny(); // cat2
    AnimalData output4 = animalShelter.dequeueCat(); // none
    AnimalData output5 = animalShelter.dequeueAny(); // dog2
    cout << output1.name << endl;
    assert(output1.name == cat1.name);
    cout << output2.name << endl;
    assert(output2.name == dog1.name);
    cout << output3.name << endl;
    assert(output3.name == cat2.name);
    // AnimalData animal;
    // assert(output4 == animal);
    cout << output5.name << endl;
    assert(output5.name == dog2.name);
    return 0;
}