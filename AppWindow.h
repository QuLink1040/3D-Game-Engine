#pragma once
#include "window.h"

class AppWindow: public Window{
	// Inherited via Window
	virtual void onCreate() override;
	virtual void onUpdate() override;
	virtual void onDestroy() override;
};

