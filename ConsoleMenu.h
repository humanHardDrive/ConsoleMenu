#ifndef __CONSOLE_MENU_H__
#define __CONSOLE_MENU_H__

/*
Menu options are formatted as such
[k] sDisplay
*/
struct MenuOption
{
	char k; /*Key to trigger the menu option*/
	char* sDisplay; /*String to display for option*/
	
	bool (*fn)(char, void*); /*Function to call when key is hit*/
	void* pData; /*Pointer to data passed to function*/
};

class ConsoleMenu
{
	public:
	ConsoleMenu(MenuOption* pOptionList);
	
	void update(char c);
	
	void clearScreen();
	void showMenu();
	
	void enableEcho() {m_bEcho = true;}
	void disableEcho() {m_bEcho = false;}
	
	private:
	void doMenu(char c);
	
	MenuOption* m_pOptionList;
	void* m_pOptionData;
	bool m_bEcho;
};

#endif