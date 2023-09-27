#include <iostream>
#include <string>

using namespace std;

class CPU {
    string name;
public:
    CPU(string name) : name(name) {}
    void cpu() {cout << "CPU name is -> " << name << endl;}
    ~CPU(){}
};
class RAM {
    string name;
    
public:
    RAM(string name) : name(name) {}
    void ram() {cout << "RAM name is -> " << name << endl;}
    ~RAM(){}
};
class SSD {
    string name;

public:
    SSD(string name) : name(name) {}
    void ssd() {cout << "SSD name is -> " << name << endl;}
    ~SSD(){}
};

class  MotherBoard {

    CPU cpu;
    RAM ram;
public:
    MotherBoard(RAM ram, CPU cpu) : ram(ram), cpu(cpu) {}
    RAM getRam() {
        return ram;
    }
    CPU getCPU(){
        return cpu;
    }
    void Mother() {cout << "Mother Board on" << endl;}
    ~MotherBoard(){}
};
class Monitor {
    string name;

public:
    Monitor(string name) : name(name) {}
    void monitor() {cout << "Monitor name is -> " << name << endl;}
    ~Monitor(){}
};
class PowerUnit {

    SSD ssd;
    CPU cpu;
public:
    PowerUnit(SSD ssd, CPU cpu) : ssd(ssd), cpu(cpu) {}

    SSD getSSD() {
        return ssd;
    }
    CPU getCPU() {
        return cpu;
    }
    
    void Unit() {
        cout << "Power Unit is on" << endl;
    }
    ~PowerUnit(){}
};

class Computer {
    
    MotherBoard mother_board;
    Monitor monitor;
    PowerUnit power_unit;


public:
    Computer(MotherBoard mother_board, PowerUnit power_unit,Monitor monitor) : 

        mother_board(mother_board), power_unit(power_unit), monitor(monitor)

    {}
    void computer() {cout << "Computer is on" << endl;}
    MotherBoard getMother() {
        return mother_board;
    }
    PowerUnit getUnit() {
        return power_unit;
    }
    Monitor getMonitor() {
        return monitor;
    }
    ~Computer(){}

    
};


int main() {
    cout << "Program has been started"  << endl << endl;

    CPU cpu = CPU("Intel");
    cout << "CPU is created" << endl;
    RAM ram = RAM("HyperX");
    cout << "RAM is created" << endl;
    SSD ssd = SSD("Kingston");
    cout << "SSD is created" << endl;


    Monitor monitor = Monitor("MSI");
    cout << "Monitor is created" << endl;
    PowerUnit power_unit =  PowerUnit(ssd, cpu);
    cout << "Power Unit is created" << endl;
    MotherBoard mother_board = MotherBoard(ram, cpu);
    cout << "Mother Board is created" << endl;

    Computer computer = Computer(mother_board, power_unit, monitor);
    cout << "Computer is created" << endl;

    computer.computer();
    computer.getMonitor().monitor();
    computer.getMother().Mother();
    computer.getMother().getCPU().cpu();
    computer.getMother().getRam().ram();
    computer.getUnit().Unit();
    computer.getUnit().getSSD().ssd();

    cout << endl;
    cout << "Program has been ended" << endl;
    return 0;
}