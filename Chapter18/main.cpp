#include "memo.h"

int main()
{
	//大战Boss前
	GameRole* lixiaoyao = new GameRole;
	lixiaoyao->GetInitState();
	lixiaoyao->StateDisplay();
 
	//保存进度
    //创建一个角色状态管理类的指针
	RoleStateCaretaker* stateAdmin = new RoleStateCaretaker;
	stateAdmin->setMemento(lixiaoyao->SaveState());
 
	//大战Boss时，损耗严重
	lixiaoyao->Fight();
	lixiaoyao->StateDisplay();
 
	//恢复之前状态               
	lixiaoyao->RecoveryState(stateAdmin->getMemento());
	lixiaoyao->StateDisplay();
 
	delete lixiaoyao;
	delete stateAdmin; 
	
	system("pause");

	return 0;
} 