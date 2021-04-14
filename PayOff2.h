#pragma once

class PayOff2
{
public:
	PayOff2() {};
	virtual double operator()(double Spot) const = 0;
	virtual ~PayOff2(){}

private:

};

class PayOffCall2 : public PayOff2
{
public:
	PayOffCall2(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffCall2() {}
private:
	double Strike;
};

class PayOffPut2 : public PayOff2
{
public:
	PayOffPut2(double Strike_);
	virtual double operator()(double Spot) const; // not implemented
	virtual ~PayOffPut2() {}
private: 
	double Strike;

};