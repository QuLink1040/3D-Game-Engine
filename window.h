#pragma once
#include <Windows.h>


class Window{
public: 
	Window();
	//Initialises window
	bool init();

	bool broadcast();

	//Releases window
	bool release();
	
	bool isRun();
	
	//Event methods
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();


protected:
	HWND m_hwnd;
	bool m_is_run;
};

