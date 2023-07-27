#include<iostream>

using namespace std; 
 
//Memento类，备忘录，此处为角色状态存储箱
class RoleStateMemento
{
private:
	int m_vit; // 生命力
	int m_atk; // 攻击力
	int m_def; // 防御力
public:
	RoleStateMemento(int vit, int atk, int def) 
    :m_vit(vit), m_atk(atk), m_def(def)//把状态存入备忘录中
    {}

    // void setVitality(int vit) { m_vit = vit; }
    int getVitality() { return m_vit; }
 
	// void setAttack(int atk) { m_atk = atk; }
	int getAttack() { return m_atk; }
 
	// void setDefense(int def) { m_def = def; }
	int getDefense() { return m_def; } 
	
};

// Originator，发起人，此处为游戏角色
class GameRole
{
private:
	int m_vit; // 生命力
	int m_atk; // 攻击力
	int m_def; // 防御力
 
public:
    // 保存角色状态
    RoleStateMemento *SaveState()
	{
		return (new RoleStateMemento(m_vit, m_atk, m_def));
	}

    // 恢复角色状态
	void RecoveryState(RoleStateMemento *memento) 
	{
		m_vit = memento->getVitality();
		m_atk = memento->getAttack();
		m_def = memento->getDefense();
	}
 
	// 获得初始状态
	void GetInitState()
	{
		m_atk = m_def = m_vit = 100;
	}
	void Fight()
	{
		m_atk = m_def = m_vit = 0;
	}
	void StateDisplay()
	{
		cout << "Role current status:" << endl;
		cout << "Vitality:" << m_vit << " "
			<< "Attack:" << m_atk << " "
			<< "Defence:" << m_def << endl;
	}
};

//Caretaker，管理者，此处为游戏角色管理类
class RoleStateCaretaker
{
private:
	RoleStateMemento *m_memento;
public:
	~RoleStateCaretaker()
	{
		delete m_memento;
	}
	void setMemento(RoleStateMemento *memento)
	{
		m_memento = memento;
	}
	RoleStateMemento *getMemento()
	{
		return m_memento;
	}
	
};
