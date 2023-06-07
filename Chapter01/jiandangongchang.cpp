#include <iostream>

//运算类抽象基类，具体运算能力都通过继承该类进行实现
class Operation   
{
protected:
	double numberA;
	double numberB;
	
public:
	void setNumberA(double const num)
	{
		this->numberA = num;
	}
	void setNumberB(double const num)
	{
		this->numberB = num;
	}

	virtual double GetResult() = 0;
};

class OperationAdd : public Operation
{
public:
	virtual double GetResult()
	{
		return numberA + numberB;
	}
};

class OperationSub : public Operation
{
public:
	virtual double GetResult()
	{
		return numberA - numberB;
	}
};

class OperationMul : public Operation
{
	virtual double GetResult()
	{
		return numberA * numberB;
	}
};


class OperationDiv : public Operation
{
	virtual double GetResult()
	{
		return numberA / numberB;
	}
};

//工厂类
class OperatinFactory
{
public:
    //静态类成员函数
	static Operation * CreateOperation(char ope)
	{
		Operation *operation = NULL;
		switch (ope)
		{
		case '+'://基类指针可以指向派生类对象
			operation = new OperationAdd();
			break;
		case '-':
			operation = new OperationSub();
			break;
		case '*':
			operation = new OperationMul();
			break;
		case '/':
			operation = new OperationSub();
			break;
		default:
			operation = NULL;
		}
		return operation;
	}
};

int main()
{
	Operation *operation = NULL;
	float num1,num2,result;
	char ope;
	while (1)
	{
		do//出口条件循环
		{
			if (std::cin.fail())
			{
				std::cin.clear();//清除错误标志

				while (std::cin.get() != '\n')
				    continue;

				std::cout << "输入错误，请重新输入：";
			}
			else
			{
				std::cout << "输入第1个参数:";
			}
			std::cin >> num1;
			std::cin.sync();//清空缓存
		} while (std::cin.fail());

		// do
		// {
		// 	if (std::cin.fail())
		// 	{
		// 		std::cin.clear();//清除错误标志

		// 		while (std::cin.get() != '\n')
		// 		    continue;

		// 		std::cout << "输入错误，请重新输入：";
		// 	}
		// 	else
		// 	{
		// 		std::cout << "输入第2个参数:";
		// 	}
		// 	std::cin >> num2;
		// 	std::cin.sync();//清空缓存
		// } while (std::cin.fail());

		std::cout << "输入第2个参数:";
		//入口条件循环
		while(!(std::cin>>num2))
		{
			std::cin.clear();
        	while(std::cin.get() != '\n')
            	continue;
			
			std::cout << "输入错误，请重新输入：";
		}

		std::cout << "输入运算符(+ - * /):";
		std::cin >> ope;
		std::cin.sync();//清空缓存

		//调用类中的静态成员函数
		operation = OperatinFactory::CreateOperation(ope);

		if (operation != NULL)
		{
			operation->setNumberA(num1);
			operation->setNumberB(num2);
			result = operation->GetResult();
			std::cout << "计算结果：" << result << std::endl;

			delete operation;
			operation = NULL;
		}
		else
		{
			std::cout << "计算结果：" << "error" << std::endl;
		}
	}
	system("pause");

    return 0;
}
//https://blog.csdn.net/justCJH/article/details/113666528