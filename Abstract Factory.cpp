#include <iostream>

using namespace std;

class Transport {
public:
    virtual void deliver() = 0;
};

class Car : public Transport {
public:
    void deliver() override {
        cout << "Delivering by car" << endl;
    }
};

class Truck : public Transport {
public:
    void deliver() override {
        cout << "Delivering by truck" << endl;
    }
};

class Train : public Transport {
public:
    void deliver() override {
        cout << "Delivering by train" << endl;
    }
};

class TransportFactory {
public:
    virtual Transport* createCar() = 0;
    virtual Transport* createTruck() = 0;
    virtual Transport* createTrain() = 0;
};

class CarFactory : public TransportFactory {
public:
    Transport* createCar() override {
        return new Car();
    }

    Transport* createTruck() override {
        return nullptr;
    }

    Transport* createTrain() override {
        return nullptr;
    }
};

class TruckFactory : public TransportFactory {
public:
    Transport* createCar() override {
        return nullptr;
    }

    Transport* createTruck() override {
        return new Truck();
    }

    Transport* createTrain() override {
        return nullptr;
    }
};

class TrainFactory : public TransportFactory {
public:
    Transport* createCar() override {
        return nullptr;
    }

    Transport* createTruck() override {
        return nullptr;
    }

    Transport* createTrain() override {
        return new Train();
    }
};

int main() {
    CarFactory* carFactory = new CarFactory();
    Transport* car = carFactory->createCar();
    car->deliver();

    TruckFactory* truckFactory = new TruckFactory();
    Transport* truck = truckFactory->createTruck();
    truck->deliver();

    TrainFactory* trainFactory = new TrainFactory();
    Transport* train = trainFactory->createTrain();
    train->deliver();

    return 0;
}
