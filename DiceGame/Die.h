#pragma once
class Die
{
private:
    int roll;
    int size;
public:
    Die(int faces);
    int getRoll();
    int rollDie();
};