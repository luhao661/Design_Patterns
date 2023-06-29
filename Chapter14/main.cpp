#include "Observer.h"
// #include "Subject.h"
#include <iostream>
#include <cstdlib>
 
//Client，客户端
int main()
{
	//VScode下编译会出错
	//怀疑是不支持C++11

	//通知者
	Subject* huhansan=new Boss();
 
	//4个观察者实例
	// Observer* tongshi1=new StockObserver("Weiguancha",huhansan);
	// Observer* tongshi2=new StockObserver("Yiguancha",huhansan);
	// Observer* tongshi3=new NBAObserver("Huohuade",huhansan);
	// Observer* tongshi4=new NBAObserver("Linshuhao",huhansan);
 
	// //***注***
	// //若输入汉字字符串，则会报错：常量中有换行符
 
	// //将4个观察者都加入到通知者的通知队列中
	// huhansan->Attach(tongshi1);
	// huhansan->Attach(tongshi2);
	// huhansan->Attach(tongshi3);
	// huhansan->Attach(tongshi4);
	
	// //魏关姹没有被老板通知到，减去。
	// huhansan->Detach(tongshi1);
 
	// huhansan->SetSubjectState("I am Hu Hansan back");
 
	// //通知
	// huhansan->Notify();
 
	// delete huhansan;
	// delete tongshi1;
	// delete tongshi2;
	// delete tongshi3;
	// delete tongshi4;
 
	// std::cout<<""<<std::endl;
 
    return 0;
}