#ifndef ADAPTER
#define ADAPTER

#include <iostream>
#include <string>

using namespace std;

// Target，定义用户实际需要的接口。
class Player 
{
protected:
	string m_name;

public:
	virtual ~Player() = default;
	explicit Player(string name) :m_name(name)
    {}
	virtual void Attack() = 0;  // 攻击
	virtual void Defense() = 0;  // 防守
};
 
class Forwads :public Player
{
public:
	explicit Forwads(string name) :Player(name) 
    {}
	void Attack()override
	{
		cout << "Forwads:" << m_name << " attack!" << endl;
	}
	void Defense()override
	{
		cout << "Forwads:" << m_name << " Defense!" << endl;
	}
};
 
 
class Guards :public Player
{
public:
	explicit Guards(string name) :Player(name) 
    {}
	void Attack()override
	{
		cout << "Guards:" << m_name << " attack!" << endl;
	}
	void Defense()override
	{
		cout << "Guards:" << m_name << " Defense!" << endl;
	}
};
 
// Adaptee，此处为外籍中锋，它的接口和Target的接口不一样，
//是现在需要适配的接口 
class ForeignCenter 
{
private:
	string m_name;

public:
	void setName(string name)
    { 
        m_name = name; 
    }

	void YaoMingAttack()
	{
		cout << "ForeignCenter:" << m_name << " attack!" << endl;
	}

	void YaoMingDefense()
	{
		cout << "ForeignCenter:" << m_name << " Defense!" << endl;
	}
 
};
 
// Adapter , 通过在内部包装一个 Adaptee 对象，把 Adaptee 转换成 Target 
class Translator : public Player  
{
private:
	ForeignCenter wjzf;

public:
	explicit Translator(string name) :Player(name) 
	{
		wjzf.setName(name);
	}

	void Attack()override
	{
		wjzf.YaoMingAttack();
	}

	void Defense()override
	{
		wjzf.YaoMingDefense();
	}
};

#endif