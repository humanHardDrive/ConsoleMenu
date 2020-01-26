#include "ConsoleMenu.h"

#include <cstdlib>

ConsoleMenu::ConsoleMenu(MenuOption* pOptionList) :
	m_pOptionList(pOptionList),
	m_pOptionFn(nullptr),
	m_pOptionData(nullptr),
	m_bEcho(false)
{
}

void ConsoleMenu::update(char c)
{	
	if(c == '\e') /*Escape key*/
	{
		/*Leave the currently executing option*/
		m_pOptionFn = nullptr;
		/*Clean up*/
		clearScreen();
		showMenu();
	}
	/*Update the currently executing option*/
	else if(m_pOptionFn)
	{
		/*Option functions return true when they're done executing*/
		if(m_pOptionFn(c, m_pOptionData))
			m_pOptionFn = nullptr;
	}
	else if(c == '\r') /*Return key*/
	{
		clearScreen();
		showMenu();
	}
	/*Try to start a new option*/
	else
		doMenu(c);
}

void ConsoleMenu::clearScreen()
{
	/*Do something*/
	/*TeraTerm: \e[2J*/
}

void ConsoleMenu::showMenu()
{
	MenuOption* pOption = m_pOptionList;
	
	if(!m_pOption)
		return;
	
	/*Null key indicates the end of a list*/
	while(pOption->k)
	{
		pOption++;
	}
}